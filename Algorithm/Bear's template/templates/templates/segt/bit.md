树状数组（裸）：

`a[i]+x: modify(a, i,x)`

`a[1...i]: query(a, i)`

树状数组（区间加，求单点值)：

维护差分`b[i]=a[i]-a[i-1]`

`a[l...r]+=x: b[l]=(a[l]+x-a[l-1])=b[l]+x, b[r+1]=(a[r+1]-a[r]-x)=b[r+1]-x`

`a[i]: b[1...i]`

树状数组（区间加，区间和）：

维护差分`b[i]=a[i]-a[i-1]`与加权差分`c[i]=ib[i]`

`a[l...r]+x: b[l]+x, b[r+1]-x, c[l]=l(a[l]-a[l-1]+x)=c[l]+lx, c[r+1]=(r+1)(a[r+1]-a[r]-x)=c[r+1]-(r+1)x`

`a[l...r]: b[1...l]+b[1...l+1]+b[1...r]=(r+1)b[1...r+1]-(r+1)b[r+1]-rb[r]-...-lb[l]-lb[l-1]=(r+1)b[1...r+1]-lb[1...l]-c[l+1...r+1]` 