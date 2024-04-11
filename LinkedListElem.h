#ifndef LINKEDLISTELEM_H_
#define LINKEDLISTELEM_H_

#include <string>
#include <map>
using namespace std;

struct LinkedListElem;
using ElPtr = LinkedListElem*;

/** tail[x] refers to the last element in the linked list representation
 * of the set with representative x
 */
static map<ElPtr,ElPtr> tail;

/** len[x] refers to the size of the set with representative x
 */
static map<ElPtr,int> len;

/**
 * elem[s] refers to the element with sting identifier s
 */
static map<string,ElPtr> elem;

struct LinkedListElem {

	string id;
    ElPtr next;
    ElPtr repr;

	LinkedListElem(string s) : id(s), next(nullptr), repr(this) {
        tail[this] = this;
        len[this] = 1;
        elem[s] = this;
    }

	string toString() { return id; }

	static ElPtr MakeSet(string s) {
        if (elem.find(s) != elem.end()) {
            // Element already exists
            return nullptr;
        }
        return new LinkedListElem(s);
    }

	static ElPtr FindSet(ElPtr x) {
        if (x == nullptr) return nullptr;
        return x->repr;
    }
	static void Union(ElPtr x, ElPtr y) {
		ElPtr xSet = FindSet(x);
		ElPtr ySet = FindSet(y);
		if (xSet != ySet) {
			if (len[xSet] < len[ySet]) { // swap xSet with ySet
				ElPtr tmp = xSet;
				xSet = ySet;
				ySet = tmp;
			}
			// find z = the last element of set xSet
			ElPtr z = tail[xSet];
			z->next = ySet;
			// remove ySet as a set representative from tail
			tail[xSet] = tail[ySet];
			len[xSet] += len[ySet];
			tail.erase(ySet);
			len.erase(ySet);
			z = ySet;
			while (z != 0) {
				z->repr = xSet;
				z = z->next;
			}
		}
	}
};

#endif /* LINKEDLISTELEM_H_ */
