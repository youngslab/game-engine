// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Component.h"
#include "SDL2/SDL.h"
#include "gl/texture.h"

class SpriteComponent : public Component {
public:
  // (Lower draw order corresponds with further back)
  SpriteComponent(class Actor *owner, int drawOrder = 100);
  ~SpriteComponent();

  virtual void Draw(class Shader *shader);
  virtual void set_texture(std::shared_ptr<gl::texture> t);

  int GetDrawOrder() const { return mDrawOrder; }
  int GetTexHeight() const { return this->height; }
  int GetTexWidth() const { return this->width; }

protected:
  std::shared_ptr<gl::texture> texture;
  int mDrawOrder;
  int width;
  int height;
};
