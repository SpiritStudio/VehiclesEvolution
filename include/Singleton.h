//
// Created by dan on 26.11.18.
//

#ifndef VEHICLESEVOLUTION_SINGLETON_H
#define VEHICLESEVOLUTION_SINGLETON_H


class Singleton {

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance();

private:
    Singleton() = default;
};


#endif //VEHICLESEVOLUTION_SINGLETON_H
