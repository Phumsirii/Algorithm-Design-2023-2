#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, int &aux){
    if (!n) return -1;
    int left=my_recur(n->left,aux),right=my_recur(n->right,aux);
    if (aux<left+right) aux=left+right;
    return 1+std::max(left,right);
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    int result=-1;
    my_recur(mRoot,result);
    return result;
}

#endif
