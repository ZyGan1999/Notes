typedef OK 1
typedef OVERFLOW -2
typedef ElemType * Triplet
Status InitTriplet(Triplet &T , ElemType v1, ElemType v2,ElemType v3){
    T = (ElemType * )malloc(3 * sizeof(ElemType));
    if(!T) exit(OVERFLOW);
    //init
    return OK
}
Status Get(Triplet T, ElemType & e){
    //
}