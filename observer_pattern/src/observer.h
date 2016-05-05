
#ifndef OBSERVER_PATT_H
#define OBSERVER_PATT_H

#include <cstdlib>

template <typename K>
class Observer {
	protected:
	/**
	 * @brief When an event is occured. This is notified.
	 * @param This is the event object. The object here can be implemented as push/pull pattern.
	 */
	virtual void notifyEvent(const K&evt);
};

/**
 * Subject of an observer pattern
 */
template <typename K>
class Subject {
	public:
	virtual void add(Observer<K>&);
	virtual void remove(Observer<K>&);
	protected:
	virtual void notifyAll(K&evt);
};

#endif // OBSERVER_PATT_H
