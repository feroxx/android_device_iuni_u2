/*
 * * Copyright (C) 2015 The CyanogenMod Project
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
 
#define CAMERA_PARAMETERS_EXTRA_C \
const char CameraParameters::SCENE_MODE_GESTURE[] = "gesture"; \
const char CameraParameters::SCENE_MODE_FOOD[] = "food"; \
const char CameraParameters::KEY_PICTURE_FRAME_SUPPORTED[] = "picture-frame-supported"; \
const char CameraParameters::KEY_PICTURE_FRAME[] = "picture-frame"; \
const char CameraParameters::PICTURE_FRAME_NORMAL[] = "normal"; \
const char CameraParameters::KEY_GESTURE_MODE[] = "gesture"; \
const char CameraParameters::GESTURE_MODE_ON[] = "on"; \
const char CameraParameters::KEY_SUPPOTED_FACE_BEAUTY_MODE[] = "face-beauty-mode-supported"; \
const char CameraParameters::KEY_FACE_BEAUTY_MODE[] = "face-beauty-mode"; \
const char CameraParameters::FACE_BEAUTY_ON[] = "on"; \
const char CameraParameters::KEY_FACE_BEAUTY_LEVEL[] = "face-beauty-level"; \
const char CameraParameters::KEY_SUPPOTED_MIRROR_MODE[] = "mirror-mode-supported"; \
const char CameraParameters::KEY_MIRROR_MODE[] = "mirror-mode"; \
const char CameraParameters::MIRROR_MODE_ON[] = "on"; \
const char CameraParameters::KEY_SCENE_DETECTION_MODE[] = "scene-detection-mode"; \
const char CameraParameters::SCENE_DETECTION_ON[] = "on"; \
const char CameraParameters::KEY_SUPPORTED_CAPTURE_MODES[] = "cap-mode-supported"; \
const char CameraParameters::KEY_CAPTURE_MODE[] = "cap-mode"; \
const char CameraParameters::CAPTURE_MODE_BURST_SHOT[] = "burstshot"; \
const char CameraParameters::CAPTURE_MODE_NIGHTSHOT_SHOT[] = "nightshot"; \
const char CameraParameters::CAPTURE_MODE_NORMAL[] = "normal"; \
const char CameraParameters::KEY_SUPPORTED_LIVE_EFFECTS[] = "live-effect-values"; \
const char CameraParameters::KEY_LIVE_EFFECT[] = "live-effect"; \
const char CameraParameters::KEY_GESTURE_SUPPORTED[] = "gesture-supported"; \
const char CameraParameters::KEY_GESTURE_EVENT_TYPE[] = "gesture-event-type"; \
const char CameraParameters::GESTURE_EVENT_OPEN_HAND_PRESENCE[] = "open-hand-presence"; \
const char CameraParameters::GESTURE_EVENT_FACE_PRESENCE[] = "face-presence"; \
const char CameraParameters::GESTURE_EVENT_FIST_PRESENCE[] = "fist-presence"; \
const char CameraParameters::PIXEL_FORMAT_YUV420SP_ADRENO[] = "yuv420sp-adreno"; \
const char CameraParameters::QC_PIXEL_FORMAT_NV12_VENUS[] = "nv12-venus"; \
const char CameraParameters::PIXEL_FORMAT_YV12[] = "yuv420p"; \
const char CameraParameters::PIXEL_FORMAT_NV12[] = "nv12"; \
const char CameraParameters::KEY_QC_SCALED_PICTURE_SIZES[] = "scaled-picture-sizes";

#define CAMERA_PARAMETERS_EXTRA_H \
    static const char SCENE_MODE_GESTURE[]; \
    static const char SCENE_MODE_FOOD[]; \
    static const char KEY_PICTURE_FRAME_SUPPORTED[]; \
    static const char KEY_PICTURE_FRAME[]; \
    static const char PICTURE_FRAME_NORMAL[]; \
    static const char KEY_GESTURE_MODE[]; \
    static const char GESTURE_MODE_ON[]; \
    static const char KEY_SUPPOTED_FACE_BEAUTY_MODE[]; \
    static const char KEY_FACE_BEAUTY_MODE[]; \
    static const char FACE_BEAUTY_ON[]; \
    static const char KEY_FACE_BEAUTY_LEVEL[]; \
    static const char KEY_SUPPOTED_MIRROR_MODE[]; \
    static const char KEY_MIRROR_MODE[]; \
    static const char MIRROR_MODE_ON[]; \
    static const char KEY_SCENE_DETECTION_MODE[]; \
    static const char SCENE_DETECTION_ON[]; \
    static const char KEY_SUPPORTED_CAPTURE_MODES[]; \
    static const char KEY_CAPTURE_MODE[]; \
    static const char CAPTURE_MODE_BURST_SHOT[]; \
    static const char CAPTURE_MODE_NIGHTSHOT_SHOT[]; \
    static const char CAPTURE_MODE_NORMAL[]; \
    static const char KEY_SUPPORTED_LIVE_EFFECTS[]; \
    static const char KEY_LIVE_EFFECT[]; \
    static const char KEY_GESTURE_SUPPORTED[]; \
    static const char KEY_GESTURE_EVENT_TYPE[]; \
    static const char GESTURE_EVENT_OPEN_HAND_PRESENCE[]; \
    static const char GESTURE_EVENT_FACE_PRESENCE[]; \
    static const char GESTURE_EVENT_FIST_PRESENCE[]; \
    static const char PIXEL_FORMAT_YUV420SP_ADRENO[]; \
    static const char QC_PIXEL_FORMAT_NV12_VENUS[]; \
    static const char PIXEL_FORMAT_YV12[]; \
    static const char PIXEL_FORMAT_NV12[]; \
    static const char KEY_QC_SCALED_PICTURE_SIZES[]; \
    const char *getStr(const char *key) const;
