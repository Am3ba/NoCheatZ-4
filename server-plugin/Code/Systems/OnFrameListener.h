/*
	Copyright 2012 - Le Padellec Sylvain

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef ONFRAMELISTENER
#define ONFRAMELISTENER

#include "Misc/temp_basiclist.h"
#include "Players/NczPlayerManager.h"

/////////////////////////////////////////////////////////////////////////
// BaseFramedTester
/////////////////////////////////////////////////////////////////////////

class OnFrameListener
{
	typedef basic_slist<OnFrameListener *> FrameListenersListT;

private:
	static FrameListenersListT m_framedTestersList;

	SlotStatus m_filter;

public:
	OnFrameListener();
	virtual ~OnFrameListener(){};

	/* Appel� par le plugin � chaque frame
	   Permet d'appeler les classes filles qui sont � l'�coute */
	static void OnFrame();

	/* Filtre du testeur, peut/doit �tre red�finit dans la classe fille */
	virtual SlotStatus GetFilter() const final {return m_filter;};

protected:
	/* Appel� par OnFrame, sert � i�trer entre les diff�rents joueurs en fonction du filtre */
	virtual void ProcessTestsOnFrame();

	/* Appel� par ProcessTestsOnFrame() lorsque le joueur correspond au filtre */
	virtual void ProcessPlayerTestOnFrame(NczPlayer* player) = 0;
	virtual void ProcessOnFrame() = 0;

	/* Permet de se mettre � l'�coute de l'�v�nement, appel� par Load/Unload des testeurs */
	static void RegisterOnFrameListener(OnFrameListener const * const listener);
	static void RemoveOnFrameListener(OnFrameListener const * const listener);
};

#endif // ONFRAMELISTENER
