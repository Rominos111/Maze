#include "../../headers/util/Observable.h"
#include "../../headers/util/Observer.h"

void Observable::addObserver(Observer *obs)  {
    if (obs == nullptr) {
        throw std::invalid_argument("Observer null");
    }

    if (observers.find(obs) == observers.end()) {
        observers.emplace(obs, obs);
    }
    else {
        // throw std::invalid_argument("Observer déjà présent");
        std::cerr << "Observer déjà présent" << std::endl;
    }
}

void Observable::deleteObserver(Observer *obs) {
    observers.erase(obs);
}

void Observable::deleteObservers() {
    observers.clear();
}

void Observable::notifyObservers() {
    notifyObservers("");
}

void Observable::notifyObservers(const std::string msg) {
    std::map<Observer*, Observer*> buffer(observers);

    for (auto const& iter : buffer) {
        Observer *value = iter.second;

        value->update(this, msg);
    }

    clearChanged();
}

bool Observable::hasChanged() {
    return changed;
}

int Observable::countObservers() {
    return observers.size();
}

void Observable::setChanged() {
    changed = true;
}

void Observable::clearChanged() {
    changed = false;
}





