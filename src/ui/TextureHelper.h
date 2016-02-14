/*
 * Texture.h
 *
 *  Created on: Feb 14, 2016
 *      Author: root
 */

#ifndef TEXTUREHELPER_H_
#define TEXTUREHELPER_H_

#include "../common/AtpmCommon.h"
#include "../common/AtpmException.h"
#include "../common/AtpmLog.h"


namespace atpm {
namespace ui {
using namespace atpm::common;

class TextureHelper {
public:
	TextureHelper(SDL_Texture *_texture);
	virtual ~TextureHelper();
	atpm_int32 Width();
	atpm_int32 Height();
	atpm_uint32 Format();
	atpm_int32 Access();
	atpm_int32 PixelCount();
	void Lock();
	void Unlock();
    void Destroy();
	atpm_uint32 *Pixels;
	atpm_int32 Pitch();
private:
	SDL_Texture *texture;
	atpm_int32 width;
	atpm_int32 height;
	atpm_uint32 format;
	atpm_int32 access;
	atpm_int32 pitch;


};

} /* namespace ui */
} /* namespace atpm */

#endif /* TEXTURE_H_ */
