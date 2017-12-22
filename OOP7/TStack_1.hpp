#ifdef VECTOR_H

#include "TVector.hpp"

template <typename Q, typename O> TStack_1<Q, O>::TStack_1() {
    head = std::make_shared<Node>(Node());
    count = 0;
}

template <typename Q, typename O> TStack_1<Q, O>::Node::Node() {
    next = nullptr;
    itemsInNode = 0;
}

template <typename Q, typename O> TStack_1<Q, O>::Node::Node(const O& item) {
	TVector<Figure>* data = new TVector<Figure>();
	data->Add(item);
	data->Resize((data->Size()) + 1);

    itemsInNode = 1;
}

/*template <typename Q, typename O> void TStack_1<Q, O>::removeByType(const int& type) {
    auto tmp = head;
    while(tmp) {
        if (tmp->itemsInNode) {
            for (int i = 0; i < 5; ++i) {
                auto iter = tmp->data.begin();

                for (int k = 0; k < tmp->data.Size(); ++k) {
                    if (iter->type() == type) {
                        tmp->data.Pop(k + 1);
                        tmp->itemsInNode--;
                        break;
                    }
                    ++iter;
                }
            }
        }
        tmp = tmp->next;
    }
}*/

template <typename Q, typename O> void TStack_1<Q, O>::push(const O& item)
{
    auto tmp = head;
    if (tmp->itemsInNode < 5) {
        tmp->data.Add(item);
        tmp->data.Resize((tmp->data.Size()) + 1);
		tmp->itemsInNode++;
    } else {
        auto newNode = std::make_shared<Node>(Node(item));
        newNode->next = head;
        head = newNode;
        ++count;
    }
}


template <typename Q, typename O> void TStack_1<Q, O>::print() {
    auto tmp = head;
    while (tmp) {
        if (tmp->itemsInNode) {
			for (int i = 0; i != tmp->data.Size(); i++) {
				tmp->data.Print_node(i);
			}
            std::cout << std::endl;
        }
        tmp = tmp->next;
    }
}


template <typename Q, typename O> void TStack_1<Q, O>::removeLesser(const double& sqr) {
    auto tmp = head;
    while(tmp) {
        if (tmp->itemsInNode) {
            for (int i = 0; i < 5; ++i) {
                auto iter = tmp->data.begin();

                for (int k = 0; k < tmp->data.Size(); ++k) {
                    if (iter->Square() < sqr) {
                        tmp->data.Delete_node(k + 1);
                        tmp->itemsInNode--;
                        break;
                    }
                    ++iter;
                }
            }
        }
        tmp = tmp->next;
    }
}

#endif