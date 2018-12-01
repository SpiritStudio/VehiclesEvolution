//
// Created by SpiritStudio on 20.11.18.
//

#include <Physics/Physics.h>
#include <Graphics/Graphics.h>

int main()
{
    Physics::getInstance().notifyMap(Graphics::getInstance());
    Physics::getInstance().notifyCars(Graphics::getInstance());

//    Every generation goes like this
//
//
//    if (Physics::getInstance().allDead())
//    {
//        Physics::getInstance().makeCars(
//                EvolutionaryAlgorithm::getInstance.makeParameters(
//                        Physics::getInstance().getLatestDistances()));
//
//        Physics::getInstance().notifyCars(Graphics::getInstance());
//    }
    Graphics::getInstance().restartClock();

    while (Graphics::getInstance().isWindowOpen())
    {
        Graphics::getInstance().handleEvents();

        Physics::getInstance().update();
        Physics::getInstance().notifyCarsPositions(Graphics::getInstance());

        Graphics::getInstance().draw();
        Graphics::getInstance().ensureConstantFrameRate();
    }

    return 0;
}