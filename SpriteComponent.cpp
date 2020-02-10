// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
//
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "SpriteComponent.h"
#include "Shader.h"
#include "Actor.h"
#include "Game.h"

SpriteComponent::SpriteComponent(Actor *owner, int drawOrder)
    : Component(owner), texture(nullptr), mDrawOrder(drawOrder), width(0),
      height(0) {
  mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent() { mOwner->GetGame()->RemoveSprite(this); }

void SpriteComponent::Draw(Shader *shader) {
  if (this->texture) {
    // Scale the quad by the width/height of texture
    Matrix4 scaleMat = Matrix4::CreateScale(static_cast<float>(width),
					    static_cast<float>(height), 1.0f);

    Matrix4 world = scaleMat * mOwner->GetWorldTransform();

    // Since all sprites use the same shader/vertices,
    // the game first sets them active before any sprite draws

    // Set world transform
    shader->SetMatrixUniform("uWorldTransform", world);
    // Set current texture
    this->texture->bind();
    // Draw quad
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
  }
}

void SpriteComponent::set_texture(std::shared_ptr<gl::texture> t) {
  if (!t)
    return;
  this->texture = t;
  std::tie(this->width, this->height) = t->size();
}
