struct Matrix{
    vector<vector<int>> mat;
    int rows,cols;
    Matrix(int n, int m){
        mat.resize(n,vector<int>(m));
        rows=n;
        cols=m;
    }
    Matrix(vector<vector<int>> values): mat(values), 
        rows(values.size()), cols(values[0].size()){

    }
    Matrix operator *(const Matrix &other){
        assert(cols==other.rows);
        Matrix product(rows,other.cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<other.cols;j++){  
                for(int k=0;k<cols;k++){
                    product.mat[i][j]+=mat[i][k]*other.mat[k][j];
                }
            }
        }
        return product;
    }
    static Matrix I(int n){
        Matrix A(n,n);
        for(int i=0;i<n;i++){
            A.mat[i][i]=1;
        }
        return A;
    }
};
Matrix bin_pow(Matrix A, int k){
    Matrix result=Matrix::I(A.rows);
    while(k>0){
        if(k&1){
            result=result*A;
        }
        A=A*A;
        k/=2;
    }
    return result;
}
void show(Matrix Q){
    for(int i=0;i<Q.rows;i++){
        for(int j=0;j<Q.cols;j++){
            cout<<Q.mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
