#include "controllers/manager.hpp"
#include <chrono>

void Manager::start()
{
    _initialize();

    if(_display.startMenu() == 2)
        _display.close();
    else
        _display.setGird();

    _data.state = Data::State::running;
    std::chrono::high_resolution_clock::time_point previousTime = std::chrono::high_resolution_clock::now();
    while (_display.isOpen())
    {
        _eventTraitment(_display.manageEvent());

        long delay = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - previousTime).count();
        if (delay < _delay * _data.speed || _data.state == Data::State::paused)
            continue;
        previousTime = std::chrono::high_resolution_clock::now();

        _lapUpdate();
    }
    _display.close();
}

void Manager::_eventTraitment(Display::events event)
{
    if (event == Display::events::reset)
        _reset();

    else if (event == Display::events::pause)
        _data.state =
            (_data.state != Data::paused) ? Data::paused : Data::running;
    else if (event == Display::events::speedUp)
        _data.speed -= (_data.speed > 0) ? 0.1 : 0;
    else if (event == Display::events::speedDown)
        _data.speed += 0.1;
    else if (event == Display::events::pheroUpdate)
        for (int colony; colony < _data.numberOfColony; colony++)
            _nestPheroInit(colony);
}

void Manager::_lapUpdate()
{
    for (unsigned int colony = 0;
         colony < _data.numberOfColony;
         colony++)
    {
        for (unsigned int ant = 0;
             ant < _data.colonies[colony].getNbAnt();
             ant++)
        {
            _antManger(colony, ant);
        }
        _antBirth(colony);
    }
    _decreaseSugarPhero();
    _display.setData();
    _display.setGird();
    _data.addLap();
}