def ober_matr(a):
    b = [[0,0],[0,0]]
    det = a[0][0]*a[1][1] - a[0][1]*a[1][0]
    
    b[0][0] = (1/det)*a[1][1]
    b[0][1] = - (1/det)*a[1][0]
    b[1][0] = - (1/det)*a[0][1]
    b[1][1] = (1/det)*a[0][0]
    
    a = b
    
    t = a[1][0]
    a[1][0] = a[0][1]
    a[0][1] = t

    return a

def df(X):
    df = [[0,0],[0,0]]
    df[0][0] = 2;
    df[0][1] = sin(X[1] + 1);
    df[1][0] = cos(X[0]);
    df[1][1] = 1;

def F(X):
    f = [0,0]
    f[0] = 2 * X[0] - cos(X[1] + 1)
    f[1] = X[1] + sin(X[0]) + 0.4
    return f

def main():
    X = [1,1]
    Xlast = [0,0]
    W = [[0,0],[0,0]]
    dX = [2,2]
    e = 0.00001


    while (abs(dX[0]) + abs(dX[1] > e)):
        Xlast = X 
        
        W = df(X)
        f = F(X)
        
        f[0] = W[0][0] * f[0] + W[0][1] * f[0]
        f[1] = W[1][0] * f[1] + W[1][1] * f[1]

        X[0] = X[0] - f[0]
        X[1] = X[1] - f[1]

        dX[0] = X[0] - Xlast[0]
        dX[1] = X[1] - Xlast[1]
    
        print(X)

if __name__ == "__main__":
     main()
