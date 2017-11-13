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
#include "u2_cam.h"
#include <utils/String8.h>
#include <string.h>
#include <stdlib.h>

namespace android {

const char CameraParameters::SCENE_MODE_GESTURE[] = "gesture";
const char CameraParameters::SCENE_MODE_FOOD[] = "food";
const char *CameraParameters::get(const char *key) const
{
    String8 v = mMap.valueFor(String8(key));
    if (v.length() == 0)
        return 0;
    return v.string();
}

String8 CameraParameters::getStr(char const *key) const
{
    char const* p = get(key);
    return  (0 != p) ? String8(p) : String8::empty();
}

}; // namespace android
