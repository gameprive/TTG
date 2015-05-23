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

#include "MissileWeapon.h"
#include "Weapon.h"

namespace Logic
{
	namespace Component
	{

        class CMissileWeapon_Linear : public IWeapon, public CBaseMissileWeapon
        {
        public:
            CMissileWeapon_Linear(CEntity* parent, CScene* scene);
            ~CMissileWeapon_Linear() {
                for (auto it = m_mapInfo.begin(); it != m_mapInfo.end();  ++it)
                    if (it->second)
                        delete it->second;
            }

            void shoot(const Vector3& src, const Vector3& dir);

            void tick(unsigned int msecs);

        private:
            unsigned  m_iMissile;
            float     m_speed;
            std::map<unsigned, Map::CMapEntity*> m_mapInfo;
            CEntity* m_parent;
            CScene*  m_scene;
        };
    }
}