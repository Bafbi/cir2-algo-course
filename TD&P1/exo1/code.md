# Sujet TD n1

## exo1

> T : tab<uint, n> = [4,3,0,1,...]  
> B : uint;  
> C : uint = 0  
> i : uint = 0  

```
for i from 0 to n - 2 do
    if T[i] < T[i+1] then
        C++
    else
        if C > B then
            B = C
        end
        C = 0;
    end
end
```

---

> T : tab<uint, n> = [4,3,0,1,...]  
> long : uint = 0  
> deb : uint = 0  
> count : uint = 0  
> i : uint = 0  

```
while n - i < long do
    while T[i] < T[i+1] do
        count++ 
    end
    if count > long then
        long = count
        deb = i
    end
    i += count    
    count = 0

end
```