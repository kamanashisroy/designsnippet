
#ifndef OBSERVER_PATT_IMPL_H
#define OBSERVER_PATT_IMPL_H

#include <vector>
#include "observer.h"

/**
 * Subject of an observer pattern
 */
template <typename K>
class SubjectImpl : Subject<K> {
	public:
	SubjectImpl();
	~SubjectImpl();
	virtual void add(Observer<K>&);
	virtual void remove(Observer<K>&);
	protected:
	virtual void notifyAll(K&evt);
	private:
	std::vector<Observer<K>*> listeners;
};

#endif // OBSERVER_PATT_IMPL_H
