//
// Created by yanpan on 2019/4/23.
//

#ifndef CC_CGOODS_H
#define CC_CGOODS_H


class CGoods {
public:
    CGoods();
    CGoods(char *name,double _price,int mount);
    CGoods(const CGoods& src);
    CGoods& operator = (const CGoods& src);
    ~CGoods();
private:
    char *_pname;
    double _price;
    int _mount;
};

#endif //CC_CGOODS_H
