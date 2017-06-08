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

const char GNCameraParameters::KEY_PICTURE_FRAME[] = "picture-frame";
const char GNCameraParameters::PICTURE_FRAME_NORMAL[] = "normal";
const char GNCameraParameters::KEY_GESTURE_MODE[] = "gesture";
const char GNCameraParameters::GESTURE_MODE_ON[] = "on";
const char GNCameraParameters::KEY_GESTURE_EVENT_TYPE[] = "gesture-event-type";
const char GNCameraParameters::GESTURE_EVENT_OPEN_HAND_PRESENCE[] = "open-hand-presence";
const char GNCameraParameters::GESTURE_EVENT_FACE_PRESENCE[] = "face-presence";
const char GNCameraParameters::GESTURE_EVENT_FIST_PRESENCE[] = "fist-presence";
const char GNCameraParameters::KEY_MIRROR_MODE[] = "mirror-mode";
const char GNCameraParameters::MIRROR_MODE_ON[] = "on";
const char GNCameraParameters::KEY_SCENE_DETECTION_MODE[] = "scene-detection-mode";
const char GNCameraParameters::SCENE_DETECTION_ON[] = "on";
const char GNCameraParameters::KEY_CAPTURE_MODE[] = "cap-mode";
const char GNCameraParameters::CAPTURE_MODE_NIGHTSHOT_SHOT[] = "nightshot";
const char GNCameraParameters::KEY_FACE_BEAUTY_MODE[] = "face-beauty-mode";
const char GNCameraParameters::FACE_BEAUTY_ON[] = "on";
const char GNCameraParameters::KEY_FACE_BEAUTY_LEVEL[] = "face-beauty-level";
const char GNCameraParameters::CAPTURE_MODE_NORMAL[] = "normal";
const char GNCameraParameters::SCENE_DETECTION_OFF[] = "off";
const char GNCameraParameters::GESTURE_EVENT_NONE[] = "none";
const char GNCameraParameters::MIRROR_MODE_OFF[] = "off";
const char GNCameraParameters::FACE_BEAUTY_OFF[] = "off";
const char GNCameraParameters::GESTURE_MODE_OFF[] = "off";
const char GNCameraParameters::CAPTURE_MODE_BURST_SHOT[] = "burstshot";
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

int GNCameraParameters::createValuesStringFromMap(/* GNCameraParameters::CameraMap const* */
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

void GNCameraParameters::setDefaultParameters(const char *mode)
{
    mParams->set("", mode);
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

