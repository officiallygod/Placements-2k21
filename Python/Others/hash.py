class HashTable:
    def __init__(self):
        self.MAX = 100
        self.arr = [[] for i in range(self.MAX)]

    def get_hash(self, key):
        h = 0
        for char in key:
            h += ord(char)
        return h % self.MAX

    # ht["march 6", 120]
    # ht["march 6", 150]
    # ht["arch 6m,", 120]
    def __setitem__(self, key, value):
        h = self.get_hash(key)
        found = False
        for idx, element in enumerate(self.arr[h]):
            if len(element) == 2 and element[0] == key:
                self.arr[h][idx] = (key, value)
                found = True
                break
        if not found:
            self.arr[h].append((key, value))

    def __getitem__(self, key):
        h = self.get_hash(key)
        return self.arr[h]

    def __delitem__(self, key):
        h = self.get_hash(key)
        self.arr[h] = 111


ht = HashTable()
ht['march 6'] = 120
ht['march 6'] = 150
# ht['march 7'] = 140
# ht['deepak'] = 150
# ht['March 17'] = 459
ht['arch 6m'] = 555
# print(ht.arr)
print(ht['arch 6m'])
# print(ht['deepak'])
# del ht['march 6']
# print(ht.arr)
# print(ht.get_hash('march 17'))
