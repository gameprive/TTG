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

#ifndef __LOGIC_LIFE_H
#define __LOGIC_LIFE_H

#include "../Component.h"

namespace Logic
{
	namespace Component
	{
        class CLife : public IComponent
        {
            DEC_FACTORY(CLife);
        public:
            CLife();
            ~CLife();

            bool spawn(CEntity* entity, CScene* scene, const Map::CMapEntity* entityInfo);
			bool decreaseLife(unsigned int num); //return life<=0
            void decreaseAllLife() { decreaseLife(*m_life); }

			virtual void deactivate() override;
           
            bool m_player;
		private:
			 int* m_life;
			 unsigned int m_enemType;
        };

        REG_FACTORY(CLife)
    }
}

#endif