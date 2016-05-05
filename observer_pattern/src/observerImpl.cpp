
#include "observer.h"
#include "observerImpl.h"

using namespace std;

template <typename K>
void SubjectImpl<K>::add(Observer<K>&observer) {
	auto it = listeners.find(&observer);
	if(it == listeners.end()) { // the observer does not exist already
		listeners.push_back(&observer);
	}
}

template <typename K>
void SubjectImpl<K>::remove(Observer<K>&observer) {
	auto it = listeners.find(&observer);
	if(it == listeners.end()) {
		return;
	}
	listeners.erase(it, it+1);
	return;
}

template <typename K>
void SubjectImpl<K>::notifyAll(K&evt) {
	for(auto const&x : listeners) {
		x.notify(evt);
	}
}


template <typename K>
SubjectImpl<K>::SubjectImpl() {
	listeners();
}

template <typename K>
SubjectImpl<K>::~SubjectImpl() {
	listeners.clear(); // XXX should it be here ? I heard it calls the destructor of the objects :(
}

