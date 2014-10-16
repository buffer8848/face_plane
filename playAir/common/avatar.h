//
//  avatardisplay.h
//  avatarpreview
//
//  Created by buffer on 13-5-23.
//  Copyright (c) 2013 com.Intel.Avatar. All rights reserved.
//

#ifndef _GMAES_COMMON_AVATAR_H_
#define _GMAES_COMMON_AVATAR_H_

#include <iostream>
#include <string>
#include <vector>

#include "paavatar.h"
//#include "../actor/commonAction.h"
//#include "../actor/animeExample.h"

//--------------------------------------------------------------------------------
class Avatar
{
public:
    Avatar();
    ~Avatar();
    
    bool Initialize(const char* pPath, const char* pModel, const char *sdmpath);
    void Uninitialize();
    
    bool SwitchModel();
    void OnDisplay(int iWidth, int iHeight);
    int OnTrack(void* pImageBuffer, int bufsize, int iWidth, int iHeight, int iWidStp);
    void GetMeshImage(unsigned char* data);
    void Reset();
    bool snapshot(int &width, int &heith, int &size, unsigned char *&data);
    bool touch(int index);
    
    //specail input/ouput
    void OnDisplay(const char *event, int width, int height);
    int OnTrack(void *image, int size, int width, int height, int step, char* out);

private:
    int iModelIndex_;
    
    PaGrayImage paImage_;
    PaAnimator  *pAnimator_;
    PaTracker   *pTracker_;
    
    PaEvent    *pEvent_;
    PaEventQueue *pQueues_[2];
    
    PaAvatarModel *pModel_;
    PaAvatarModel *pNextModel_;
    std::vector<std::string> vctstrModels_;
};

//--------------------------------------------------------------------------------

static std::vector<std::string> ListDir(const char *path, int level = 0);
static void color_convert_common(const unsigned char *pY,
                                 const unsigned char *pUV,int width,
                                 int height, unsigned char *buffer, int grey);
static int cxImgRotate (PaGrayImage *src, PaGrayImage *dst, int type);

//---------------------------------------------------------------------------------
//add by buffer
#define RECIPROCAL_UCHAR (1/255.0)
#define PI 3.1415926f
static float ucharTofloat(unsigned char value) { return (float)((float)value*RECIPROCAL_UCHAR);}
static float uint16Tofloat_t(unsigned short value) { return (float)((float)value / 65535.0);}
typedef struct {
    unsigned int type;
    unsigned int version;
    unsigned short size;
    unsigned char subversion;
    unsigned char reserveda;
    
    // action element
    unsigned short head_rx;
    unsigned short head_ry;
    unsigned short head_rz;
    unsigned short head_tx;
    unsigned short head_ty;
    unsigned short head_scale;
    
    unsigned char blendshape[36];
    unsigned char reservedb[28];
} miniEvent;

#endif /* defined(__avatarpreview__avatardisplay__) */
