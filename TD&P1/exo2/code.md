# Sujet TD n1

## exo2

> T : tab<char, n> = "arc"
> P : tab<tab<char, n>, n^n>
> premiere char = 'a'
> derniere char 'r'

```
fn succ(&lettre, pos) do
    lettre[i] = lettre[(i + 1) % (n - 1)]
end

fn suivant(&mot) do
    uint i = n - 1
    while succ(mot[i], i) == premiere do
        i --
    end
end

fn generateur(mot) do
    while mot[n-1] != derniere do
        show(suivant(mot))
    end

```

000
001
002
010
011
012