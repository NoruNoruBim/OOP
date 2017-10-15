#ifndef ITEM_H
#define ITEM_H

//#include "figure.hpp"
#include "figure_pentagon.hpp"
#include "figure_hexagon.hpp"
#include "figure_octagon.hpp"
#include <memory>

class TVectorItem {
    private:
        std::shared_ptr<Figure> figure;
    public:
        TVectorItem(std::shared_ptr<Figure>& figure);
        //TVectorItem(const std::shared_ptr<Pentagon>& orig);
        friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem>& obj);

        std::shared_ptr<Figure> GetFigure() const;


        virtual ~TVectorItem();
};

#endif
