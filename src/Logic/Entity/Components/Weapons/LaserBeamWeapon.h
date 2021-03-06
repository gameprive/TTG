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

#ifndef __LOGIC_LASEBEAMRWEAPON_H
#define __LOGIC_LASEBEAMRWEAPON_H

#include "Weapon.h"
#include <Common/Util/Math.h>
#include <Logic/Entity/Entity.h>

namespace Ogre
{
	class Entity;
	class SceneManager;
	class SceneNode;
}

namespace Map { class CMapEntity; }

namespace physx { class PxScene; }

namespace Common
{
    namespace Particles
    {
        class CParticleManager;
    }

    namespace Physic
    {
        class CPhysicManager;
    }
}

using namespace Common::Particles;
using namespace Common::Physic;

namespace Logic
{
    namespace Component
    {
        class CLaserBeam : public IWeapon
        {
        public:
            CLaserBeam(CScene*, Ogre::SceneManager*, physx::PxScene*, const Map::CMapEntity*, CEntity*);
            ~CLaserBeam();

            void shoot(const Vector3& src, const Vector3& dir, unsigned int msecs);

			virtual void releaseTrigger();

			virtual void tick(unsigned int) override;

            /**
                Set parameters for a weapon.
            */
            void setWeapon( const float& damage, const float& cadence, const float& range, 
                const float& speed, int charger, int cost, const std::string& soundFile, Common::Data::Weapons_t type = Common::Data::Weapons_t::END);

        private:
		   Ogre::SceneManager*  m_sceneMngr;
           physx::PxScene*      m_pxScene;
           CScene*              m_scene;
           Vector3              m_currPos;
           CParticleManager*    m_particles;
           CPhysicManager*      m_phyMngr;
           Ogre::Ray            m_ray;
           CEntity*             m_player;
           unsigned             m_cost;
           unsigned*            m_energy;
           int                  m_interval;
           int                  m_auxInterval;
		   float				m_time;
		   std::string			m_soundName;
		   std::string			m_soundExplosion;
		   bool					m_shooting;
		   float				m_acumCost;
		   float				m_acumDamage;
        };
    }
}

#endif