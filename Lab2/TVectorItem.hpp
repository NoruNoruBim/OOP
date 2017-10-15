#ifndef ITEM_H
#define ITEM_H

#include "figure_pentagon.hpp"

class TVectorItem {
    private:
        Pentagon pentagon;
    public:
        TVectorItem(Pentagon& pentagon);
        TVectorItem(const TVectorItem& orig);
        friend std::ostream& operator<<(std::ostream& os, const TVectorItem& obj);

        Pentagon GetPentagon() const;


        virtual ~TVectorItem();
};

#endif
