/**
  *  @Desctiption:
  *      Define and implement parameters for Gionee features.
  *
  *	@Author : wutz
  *	@Date    : 2013-09-24
  *	@Email   : wutz@gionee.com
  *	@Version: 1.0 
  */

#ifndef ORIGINAL_VERSION
  
#define LOG_TAG "GNCameraParameters"
#include <utils/Log.h>

#include <string.h>
#include <stdlib.h>

#include "GNCameraParameters.h"
#include <camera/CameraParametersExtra.h>

namespace qcamera {

//Picture frame
const char GNCameraParameters::KEY_PICTURE_FRAME[] 					= "picture-frame";
const char GNCameraParameters::KEY_PICTURE_FRAME_SUPPORTED[] 		= "picture-frame-supported";
const char GNCameraParameters::PICTURE_FRAME_NORMAL[] 				= "normal";

// Gesture shot mode
const char GNCameraParameters::KEY_GESTURE_SUPPORTED[] 				= "gesture-supported";
const char GNCameraParameters::KEY_GESTURE_MODE[] 					= "gesture";
const char GNCameraParameters::GESTURE_MODE_ON[] 					= "on";
const char GNCameraParameters::GESTURE_MODE_OFF[] 					= "off";

//Face beauty mode
const char GNCameraParameters::KEY_FACE_BEAUTY_MODE[] 				= "face-beauty-mode";
const char GNCameraParameters::KEY_SUPPOTED_FACE_BEAUTY_MODE[] 		= "face-beauty-mode-supported";
const char GNCameraParameters::KEY_FACE_BEAUTY_LEVEL[]				= "face-beauty-level";
const char GNCameraParameters::KEY_SLENDER_FACE_LEVEL[]				= "slender-face-level";
const char GNCameraParameters::KEY_SKIN_SOFTEN_LEVEL[]				= "skin-soften-level";
const char GNCameraParameters::KEY_EYE_ENLARGMENT_LEVEL[]			= "eye-enlargment-level";
const char GNCameraParameters::FACE_BEAUTY_ON[] 					= "on";
const char GNCameraParameters::FACE_BEAUTY_OFF[] 					= "off";   

const char GNCameraParameters::KEY_FACE_BEAUTY_SUB_MODE[]			= "face-beauty-sub-mode";
const char GNCameraParameters::KEY_FACE_BEAUTY_AGEGENDER_LEVEL[]	= "face-beauty-agegender-level";
const char GNCameraParameters::FACE_BEAUTY_AGEGENDER_MODE[]			= "face-beauty-agegender-mode";
const char GNCameraParameters::FACE_BEAUTY_DEFAULT_MODE[]			= "face-beauty-default-mode";

//ageGender-detection
const char GNCameraParameters::KEY_AGEGENDER_DETECTION_MODE[] = "agegender-detection-mode";
const char GNCameraParameters::KEY_SUPPOTED_AGEGENDER_DETECTION_MODE[] = "agegender-detection-mode-supported";
const char GNCameraParameters::AGEGENDER_DETECTION_ON[] = "on";
const char GNCameraParameters::AGEGENDER_DETECTION_OFF[] = "off";

//Pic zoom mode
const char GNCameraParameters::KEY_PICZOOM_MODE[] 					= "piczoom-mode";
const char GNCameraParameters::PICZOOM_MODE_ON[] 					= "on";
const char GNCameraParameters::PICZOOM_MODE_OFF[] 					= "off";

//Mirror mode
const char GNCameraParameters::KEY_MIRROR_MODE[] 					= "mirror-mode";
const char GNCameraParameters::KEY_SUPPOTED_MIRROR_MODE[] 			= "mirror-mode-supported";
const char GNCameraParameters::MIRROR_MODE_ON[] 					= "on";
const char GNCameraParameters::MIRROR_MODE_OFF[] 					= "off";	

// Gesture event type
const char GNCameraParameters::KEY_GESTURE_EVENT_SUPPORTED[] 		= "gesture-event-supported";
const char GNCameraParameters::KEY_GESTURE_EVENT_TYPE[] 			= "gesture-event-type";
const char GNCameraParameters::GESTURE_EVENT_NONE[] 				= "none";
const char GNCameraParameters::GESTURE_EVENT_OPEN_HAND_PRESENCE[] 	= "open-hand-presence";
const char GNCameraParameters::GESTURE_EVENT_FIST_PRESENCE[] 		= "fist-presence";
const char GNCameraParameters::GESTURE_EVENT_FACE_PRESENCE[] 		= "face-presence";

// Scene detection mode
const char GNCameraParameters::KEY_SCENE_DETECTION_MODE[] 			= "scene-detection-mode";
const char GNCameraParameters::KEY_SUPPOTED_SCENE_DETECTION_MODE[] 	= "scene-detection-mode-supported";
const char GNCameraParameters::SCENE_DETECTION_ON[] 				= "on";
const char GNCameraParameters::SCENE_DETECTION_OFF[] 				= "off";

// Capture mode
const char GNCameraParameters::KEY_CAPTURE_MODE[] 					= "cap-mode";
const char GNCameraParameters::KEY_SUPPORTED_CAPTURE_MODES[] 		= "cap-mode-supported";
const char GNCameraParameters::CAPTURE_MODE_NORMAL[] 				= "normal";
const char GNCameraParameters::CAPTURE_MODE_BURST_SHOT[] 			= "burstshot";
const char GNCameraParameters::CAPTURE_MODE_NIGHTSHOT_SHOT[] 		= "nightshot";
const char GNCameraParameters::CAPTURE_MODE_PICZOOM_SHOT[]			= "piczoom";

const char GNCameraParameters::KEY_BURST_SHOT_NUM[] 				= "burst-num";

// Live effect
const char GNCameraParameters::KEY_LIVE_EFFECT[] 					= "live-effect";
const char GNCameraParameters::KEY_SUPPORTED_LIVE_EFFECTS[] 		= "live-effect-values";
const char GNCameraParameters::LIVE_EFFECT_NONE[] 					= "none";
const char GNCameraParameters::LIVE_EFFECT_ANTIQUE[] 				= "antique";
const char GNCameraParameters::LIVE_EFFECT_CARTOON[] 				= "cartoon";
const char GNCameraParameters::LIVE_EFFECT_EMBOSS[] 				= "emboss";
const char GNCameraParameters::LIVE_EFFECT_FLIP[] 					= "flip";
const char GNCameraParameters::LIVE_EFFECT_FOG[] 					= "fog";
const char GNCameraParameters::LIVE_EFFECT_GRAYSCALE[] 				= "grayscale";
const char GNCameraParameters::LIVE_EFFECT_LOMO_BLUE[] 				= "lomo-blue";
const char GNCameraParameters::LIVE_EFFECT_LOMO_GREEN[] 			= "lomo-green";
const char GNCameraParameters::LIVE_EFFECT_LOMO_NEUTRAL[] 			= "lomo-neutral";
const char GNCameraParameters::LIVE_EFFECT_LOMO_RED[] 				= "lomo-red";
const char GNCameraParameters::LIVE_EFFECT_LOMO_YELLOW[] 			= "lomo-yellow";
const char GNCameraParameters::LIVE_EFFECT_MAGICPEN[] 				= "magicpen";
const char GNCameraParameters::LIVE_EFFECT_MILKY[] 					= "milky";
const char GNCameraParameters::LIVE_EFFECT_MIRROR[] 				= "mirror";
const char GNCameraParameters::LIVE_EFFECT_NEGATIVE[] 				= "negative";
const char GNCameraParameters::LIVE_EFFECT_OILY[] 					= "oily";
const char GNCameraParameters::LIVE_EFFECT_PAINT[] 					= "paint";
const char GNCameraParameters::LIVE_EFFECT_SEPIA[] 					= "sepia";
const char GNCameraParameters::LIVE_EFFECT_SKETCH_COLOR[]			= "sketch-color";
const char GNCameraParameters::LIVE_EFFECT_SKETCH_GRAY[] 			= "sketch-gray";
const char GNCameraParameters::LIVE_EFFECT_SOLARIZE[] 				= "solarize";
const char GNCameraParameters::LIVE_EFFECT_STAMP[] 					= "stamp";
const char GNCameraParameters::LIVE_EFFECT_DOF[] 					= "dof";
const char GNCameraParameters::LIVE_EFFECT_VIGNETTING[] 			= "vignetting";
const char GNCameraParameters::LIVE_EFFECT_WARP_FISHEYE[] 			= "warp-fisheye";
const char GNCameraParameters::LIVE_EFFECT_WARP_ALIENSCUM[] 		= "warp-alienscum";
const char GNCameraParameters::LIVE_EFFECT_WARP_BIGBUPPA[] 			= "warp-bigbuppa";
const char GNCameraParameters::LIVE_EFFECT_WARP_BOOZIEBOWL[] 		= "warp-booziebowl";
const char GNCameraParameters::LIVE_EFFECT_WARP_CONEHEAD[] 			= "warp-conehead";
const char GNCameraParameters::LIVE_EFFECT_WARP_FUNKYFRESH[] 		= "warp-funkyfresh";
const char GNCameraParameters::LIVE_EFFECT_WARP_JELLYBELLY[] 		= "warp-jellybelly";
const char GNCameraParameters::LIVE_EFFECT_WARP_PETTYPETIT[] 		= "warp-pettypetit";
const char GNCameraParameters::LIVE_EFFECT_WARP_EYEBALLEDEVY[] 		= "warp-eyeballedevy";
const char GNCameraParameters::LIVE_EFFECT_WARP_SPEEDYWEED[] 		= "warp-speedyweed";
const char GNCameraParameters::LIVE_EFFECT_MOSAIC[] 				= "mosaic";
const char GNCameraParameters::LIVE_EFFECT_FROST[] 					= "frost";
const char GNCameraParameters::LIVE_EFFECT_MOON_LIGHT[] 			= "moon-light";
const char GNCameraParameters::LIVE_EFFECT_NOISE[] 					= "noise";
const char GNCameraParameters::LIVE_EFFECT_WATER_COLOR[] 			= "water-color";
const char GNCameraParameters::LIVE_EFFECT_FLEETINGTIME[] 			= "fleetingtime";
const char GNCameraParameters::LIVE_EFFECT_CRAYON[] 				= "crayon";
const char GNCameraParameters::LIVE_EFFECT_SNOWFLAKES[] 			= "snowflakes";
const char GNCameraParameters::LIVE_EFFECT_LIGHTBEAM[] 				= "lightbeam";
const char GNCameraParameters::LIVE_EFFECT_REFLECTION[] 			= "reflection";
const char GNCameraParameters::LIVE_EFFECT_SUNSET[] 				= "sunset";
const char GNCameraParameters::LIVE_EFFECT_REVERSAL[] 				= "reversal";
const char GNCameraParameters::LIVE_EFFECT_WARMLOMO[] 				= "warmlomo";
const char GNCameraParameters::LIVE_EFFECT_COLDLOMO[] 				= "coldlomo";
const char GNCameraParameters::LIVE_EFFECT_SOFTPINK[] 				= "softpink";
const char GNCameraParameters::LIVE_EFFECT_JAPANBACKLIGHT[] 		= "japan-backlight";
const char GNCameraParameters::LIVE_EFFECT_COSMETOLOGY_BACKLIGHT[] 	= "cosmetology-backlight";
const char GNCameraParameters::LIVE_EFFECT_FINEFOOD[]				= "finefood";
const char GNCameraParameters::LIVE_EFFECT_BLACKWHITET[]			= "blackwhite";

}; //namespace qcamera

#endif //ORIGINAL_VERSION
