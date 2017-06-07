/*
 * Copyright (C) 2015 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>

#include <utils/Log.h>

#include <camera/CameraParameters.h>
#include <camera/CameraParameters_EXT.h>

namespace android {

const char GNCameraParameters::SCENE_MODE_BURST[] = "burst";
const char GNCameraParameters::SCENE_MODE_MANUAL[] = "manual";
const char GNCameraParameters::SCENE_MODE_PANORAMA[] = "panorama";
const char GNCameraParameters::SCENE_MODE_PANORAMA_360[] = "panorama360";
const char GNCameraParameters::SCENE_MODE_TEXT[] = "text";
const char GNCameraParameters::SCENE_MODE_ZOE[] = "zoe";
const char GNCameraParameters::ISO_AUTO[] = "auto";
const char GNCameraParameters::ISO_HJR[] = "ISO_HJR";
const char GNCameraParameters::ISO_100[] = "ISO100";
const char GNCameraParameters::ISO_200[] = "ISO200";
const char GNCameraParameters::ISO_400[] = "ISO400";
const char GNCameraParameters::ISO_800[] = "ISO800";
const char GNCameraParameters::ISO_1600[] = "ISO1600";
const char GNCameraParameters::VIDEO_HFR_OFF[] = "off";
const char GNCameraParameters::VIDEO_HFR_2X[] = "60";
const char GNCameraParameters::VIDEO_HFR_3X[] = "90";
const char GNCameraParameters::VIDEO_HFR_4X[] = "120";
const char GNCameraParameters::VIDEO_HFR_5X[] = "150";
const char GNCameraParameters::KEY_FASTVIDEO_FPS60_1080P_SUPPORTED[] = "video-1080p60fps-supported";
const char GNCameraParameters::KEY_SLOW_MOTION_SUPPORTED[] = "video-slow-motion-supported";
const char GNCameraParameters::KEY_SLOW_MOTION_MULTIPLE[] = "slow-motion-x";
const char GNCameraParameters::KEY_SLOW_MOTION_RES[] = "slow-motion-res";
const char GNCameraParameters::KEY_FASTVIDEO_FPS60_SUPPORTED[] = "video-720p60fps-supported";
const char GNCameraParameters::KEY_CONTIBURST_TAKE[] = "take";
const char GNCameraParameters::KEY_CONTIBURST_SUPPORTED_MODE[] = "contiburst-support-mode";
const char GNCameraParameters::KEY_NON_ZSL_MANUAL_MODE[] = "non-zsl-manual-mode";
const char GNCameraParameters::KEY_VIDEO_MODE[] = "video-mode";
const char GNCameraParameters::KEY_FORCE_USE_AUDIO_ENABLED[] = "force-use-audio-enabled";
const char GNCameraParameters::KEY_SLOW_MOTION_VERSION[] = "slow-motion-version";
const char GNCameraParameters::KEY_SAVE_MIRROR[] = "save-mirror";
const char GNCameraParameters::DENOISE_ON[] = "denoise-on";
const char GNCameraParameters::DENOISE_OFF[] = "denoise-off";

#define ORIENTATION_PORTRAIT 1
#define ORIENTATION_LANDSCAPE 2

// Parse string like "640x480" or "10000,20000"
static int parse_pair(const char *str, int *first, int *second, char delim,
                      char **endptr = NULL)
{
    // Find the first integer.
    char *end;
    int w = (int)strtol(str, &end, 10);
    // If a delimeter does not immediately follow, give up.
    if (*end != delim) {
        ALOGE("Cannot find delimeter (%c) in str=%s", delim, str);
        return -1;
    }

    // Find the second integer, immediately after the delimeter.
    int h = (int)strtol(end+1, &end, 10);

    *first = w;
    *second = h;

    if (endptr) {
        *endptr = end;
    }

    return 0;
}

static void parseSizesList(const char *sizesStr, Vector<Size> &sizes)
{
    if (sizesStr == 0) {
        return;
    }

    char *sizeStartPtr = (char *)sizesStr;

    while (true) {
        int width, height;
        int success = parse_pair(sizeStartPtr, &width, &height, 'x',
                                 &sizeStartPtr);
        if (success == -1 || (*sizeStartPtr != ',' && *sizeStartPtr != '\0')) {
            ALOGE("Picture sizes string \"%s\" contains invalid character.", sizesStr);
            return;
        }
        sizes.push(Size(width, height));

        if (*sizeStartPtr == '\0') {
            return;
        }
        sizeStartPtr++;
    }
}

GNCameraParameters::GNCameraParameters()
{
}

GNCameraParameters::GNCameraParameters(CameraParameters *p)
    : mParams(p)
{
}

GNCameraParameters::~GNCameraParameters()
{
}

int GNCameraParameters::get_from_attr(const char *path, char *buf, size_t len)
{
    FILE *fp;
    int ret = 0;

    fp = fopen(path, "rb");
    if (fp == NULL) {
        ret = -ENOENT;
        return ret;
    }

    memset(buf, 0, len);
    if (fread(buf, 1, 4, fp) > 4) {
        ret = -1;
    }
    fclose(fp);

    return ret;
}

bool GNCameraParameters::check_flashlight_restriction()
{
    /* Just lie and always say we are able to use the flashlight */
    return false;
}

int GNCameraParameters::lookupAttr(/* GNCameraParameters::CameraMap const* */
        void *cameraMap, int a3, const char *a4)
{
    return -2;
}

const char * GNCameraParameters::getPreviewFrameRateMode() const
{
    return mParams->get("preview-frame-rate-mode");
}

void GNCameraParameters::setPreviewFrameRateMode(const char *mode)
{
    mParams->set("preview-frame-rate-mode", mode);
}

void GNCameraParameters::setPictureFrame(const char *mode)
{
    mParams->set("picture-frame", mode);
}

void GNCameraParameters::setBrightnessLumaTargetSet(int brightness, int luma)
{
    char buf[32];
    snprintf(buf, 32, "%d,%d", brightness, luma);
    mParams->set("brightness-luma-target-set", buf);
}

int GNCameraParameters::getBrightnessLumaTargetSet(int *brightness, int *luma) const
{
    const char *p;
    *brightness = *luma = -1;
    p = mParams->get("brightness-luma-target-set");
    if (p == 0) return -1;
    parse_pair(p, brightness, luma, ',');
    return 0;
}

void GNCameraParameters::setTouchIndexAec(int x, int y)
{
    char buf[32];
    snprintf(buf, 32, "%dx%d", x, y);
    mParams->set("touch-index-aec", buf);
}

void GNCameraParameters::getTouchIndexAec(int *x, int *y)
{
    const char *p;
    *x = *y = -1;
    p = mParams->get("touch-index-aec");
    if (p == 0) return;
    parse_pair(p, x, y, 'x');
}

void GNCameraParameters::setTouchIndexAf(int x, int y)
{
    char buf[32];
    snprintf(buf, 32, "%dx%d", x, y);
    mParams->set("touch-index-af", buf);
}

void GNCameraParameters::getTouchIndexAf(int *x, int *y)
{
    const char *p;
    *x = *y = -1;
    p = mParams->get("touch-index-af");
    if (p == 0) return;
    parse_pair(p, x, y, 'x');
}

void GNCameraParameters::setZsl(const char *mode)
{
    mParams->set("zsl", mode);
}

const char * GNCameraParameters::getZsl() const
{
    return mParams->get("zsl");
}

void GNCameraParameters::setRawSize(int x, int y)
{
    char buf[32];
    snprintf(buf, 32, "%dx%d", x, y);
    mParams->set("raw-size", buf);
}

void GNCameraParameters::getRawSize(int *x, int *y)
{
    const char *p;
    *x = *y = -1;
    p = mParams->get("raw-size");
    if (p == 0) return;
    parse_pair(p, x, y, 'x');
}

void GNCameraParameters::getMeteringAreaCenter(int *x, int *y) const
{
    const char *p;
    *x = *y = -2000;
    p = mParams->get("metering-areas");
    parse_pair(p, x, y, 'x');
    *x /= 2;
    *y /= 2;
}

void GNCameraParameters::getSupportedHfrSizes(Vector<Size> &sizes) const
{
    const char *hfrSizesStr = mParams->get("hfr-size-values");
    parseSizesList(hfrSizesStr, sizes);
}

void GNCameraParameters::setPreviewFpsRange(int min, int max)
{
    char buf[32];
    snprintf(buf, 32, "%d,%d", min, max);
    mParams->set("preview-fps-range", buf);
}

int GNCameraParameters::getOrientation() const
{
    /* Presumably portrait is 1 and landscape is 2 */
    const char *p;
    p = mParams->get("orientation");
    if (p && !strcmp(p, "portrait"))
        return ORIENTATION_PORTRAIT;
    else
        return ORIENTATION_LANDSCAPE;
}

void GNCameraParameters::setOrientation(int orientation)
{
    switch (orientation) {
        case ORIENTATION_PORTRAIT:
            mParams->set("orientation", "portrait");
            break;
        case ORIENTATION_LANDSCAPE:
            mParams->set("orientation", "landscape");
            break;
    }
}

} // android

