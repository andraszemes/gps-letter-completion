# GPS Letter Completion


## Compilation
```
g++ -std=c++11 app.cpp -o app.exe
```


## Execution
```
app *input* < places.txt
```


## Implementation details

### Input database of addresses
The database is a text file *[places.txt]* containing place names on individual rows. Each row can have a maximum length of 100 characters. The list of addresses is unordered. The data is case insensitive. The program must support at least 42 addresses.

### Program output
#### Exact match found
```
Match found
```

#### Address found
```
Found: S
```

#### Address requires further specification
```
Enable: CHARS
```

#### Address not found
```
Not found
```