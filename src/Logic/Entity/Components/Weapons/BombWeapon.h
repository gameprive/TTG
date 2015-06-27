/*
 	Copyright 2015 Francisco Javier Martinez Garcia
	Copyright 2015 Alvaro Perez Corral
	Copyright 2015 Luis Valero Martin
	Copyright 2015 Adrian Vizcaino Gonzalez
	This file is part of Through the galaxy.
	Through the galaxy is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.
	Through the galaxy is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with Through the galaxy.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LOGIC_BOMBWEAPON_H
#define __LOGIC_BOMBWEAPON_H

#include "Weapon.h"
#include "MissileWeapon.h"

namespace Common
{
    namespace Particles
    {
        class CParticleManager;
    }
}

using namespace Common::Particles;
using namespace std;

namespace Logic
{
    namespace Component
    {
        /*
        *Basiclay is like a missile but without any kind of movement
        */
        class CBombWeapon : public IWeapon, public CBaseMissileWeapon
        {
        public:
            CBombWeapon(CEntity* parent, CScene* scene);
            ~CBombWeapon();

            void shoot(const Vector3& src);

            void tick(unsigned int msecs);

            /**
                Set parameters for a weapon.
            */
			void setWeapon(const float& damage, const unsigned int& cost, const float& range, 
                           Common::Data::Weapons_t type = Common::Data::Weapons_t::END);

        private:
            map<unsigned, Map::CMapEntity*> m_mapInfo;
            CEntity*          m_parent;
            CScene*           m_scene;
			unsigned          m_cost;
            float             m_timeToExplode;
            CParticleManager* m_particles;
			unsigned int	  m_currBomb;
        };
    }
}

#endif