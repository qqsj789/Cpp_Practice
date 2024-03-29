#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <queue>
#include <future>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */

template <typename T>
T MessageQueue<T>::receive()
{
    // FP.5a : The method receive should use std::unique_lock<std::mutex> and _condition.wait()
    // to wait for and receive new messages and pull them from the queue using move semantics.
    // The received object should then be returned by the receive function.
    std::unique_lock<std::mutex> uLock(_mutex);
    _cond.wait(uLock, [this] { return !_msgs.empty(); });

    T message = std::move(_msgs.back());
    _msgs.pop_back();

    return message;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    // FP.4a : The method send should use the mechanisms std::lock_guard<std::mutex>
    // as well as _condition.notify_one() to add a new message to the queue and afterwards send a notification.
    std::lock_guard<std::mutex> uLock(_mutex);

    // add vector to queue
    std::cout << "   Message " << msg << " will be added to the queue" << std::endl;
    _msgs.push_back(std::move(msg));
    _cond.notify_one();
}

/* Implementation of class "TrafficLight" */

TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::TRed;
    _msg_queue = std::make_shared<MessageQueue<TrafficLightPhase>>();
}

void TrafficLight::waitForGreen()
{
    // FP.5b : add the implementation of the method waitForGreen, in which an infinite while-loop
    // runs and repeatedly calls the receive function on the message queue.
    // Once it receives TrafficLightPhase::green, the method returns.
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (_msg_queue->receive() == TGreen)
        {
            return;
        }
    }
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}

void TrafficLight::setCurrentPhase(const TrafficLightPhase color)
{
    _currentPhase = color;
}

void TrafficLight::simulate()
{
    // FP.2b : Finally, the private method „cycleThroughPhases“ should be started in a thread when the public method „simulate“ is called. To do this, use the thread queue in the base class.
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    // FP.2a : Implement the function with an infinite loop that measures the time between two loop cycles
    // and toggles the current phase of the traffic light between red and green and sends an update method
    // to the message queue using move semantics. The cycle duration should be a random value between 4 and 6 seconds.
    // Also, the while-loop should use std::this_thread::sleep_for to wait 1ms between two cycles.
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> uDistr(4, 6);

    std::unique_lock<std::mutex> lock(_mtx);
    lock.unlock();

    double randomPhase = uDistr(eng);
    std::chrono::time_point<std::chrono::system_clock> lastUpdate;
    lastUpdate = std::chrono::system_clock::now();

    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        long timeSinceLastUpdate = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - lastUpdate).count();

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        if (timeSinceLastUpdate >= randomPhase)
        {
            if (_currentPhase == TRed)
            {
                _currentPhase = TGreen;
            }
            else
            {
                _currentPhase = TRed;
            }

            auto msg = _currentPhase;
            auto is_sent = std::async(std::launch::async, &MessageQueue<TrafficLightPhase>::send, _msg_queue, std::move(msg));
            is_sent.wait();

            lastUpdate = std::chrono::system_clock::now();

            randomPhase = uDistr(eng);
        }
    }
}