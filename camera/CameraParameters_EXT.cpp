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

void GNCameraParameters::setDefaultParameters(const char *mode)
{
    mParams->set("", mode);
}

void GNCameraParameters::setPictureFrame(const char *mode)
{
    mParams->set("picture-frame", mode);
}

} // android

