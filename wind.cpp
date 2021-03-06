/* Blip 'n Blup
// Copyright (C) 2016 LucKey Productions (luckeyproductions.nl)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// Commercial licenses are available through frode@lindeijer.nl
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "wind.h"
#include "bubble.h"

Wind::Wind(Context* context) : LogicComponent(context)
{
}

void Wind::RegisterObject(Context *context)
{
    context->RegisterFactory<Wind>();
}

void Wind::Update(float timeStep)
{
    if (node_->HasComponent<Container>() && !node_->GetComponent<Container>()->IsEmpty())
        return;

    RigidBody* rigidBody{node_->GetComponent<RigidBody>()};
    if (rigidBody){
        rigidBody->ApplyForce(Vector3::LEFT *
                              MC->Sine(0.23f, -10.0f, 50.0f, 0.1f * node_->GetPosition().y_) * timeStep);
    }
}

