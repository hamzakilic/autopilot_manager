/*
 * Texture.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: root
 */

#include "../ui/TextureHelper.h"

namespace atpm {
namespace ui {

TextureHelper::TextureHelper(SDL_Texture * _texture):texture(_texture),width(0),height(0),format(0),access(0),pitch(0),Pixels(0) {
   if(SDL_QueryTexture(texture,&format,&access,&width,&height))
	   throw AtpmException("TextureHelper Init Failed:",SDL_GetError());

}

TextureHelper::~TextureHelper() {

}

atpm_int32 TextureHelper::Width(){
return width;
}
atpm_int32 TextureHelper::Height(){
		return height;
}
atpm_uint32 TextureHelper::Format(){

	return format;
}
atpm_int32 TextureHelper::Access(){

	return access;
}

void TextureHelper::Lock(){
	if(SDL_LockTexture(texture,NULL,(void**)&Pixels,&pitch)){
		throw AtpmException("TextureHelper Lock failed:",SDL_GetError());
	}
}
void TextureHelper::Unlock(){
    SDL_UnlockTexture(texture);
}
void TextureHelper::Destroy(){
	if(texture)
	SDL_DestroyTexture(texture);
	texture=NULL;
}
atpm_int32 TextureHelper::PixelCount(){
	return pitch/4*height;
}

atpm_int32 TextureHelper::Pitch(){
	return pitch;
}


} /* namespace ui */
} /* namespace atpm */
