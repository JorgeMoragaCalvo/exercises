#include "hashtable.h"

typedef struct entry {
    char *key;
    size_t keylength;
    void *object;
    struct entry *netx;
} entry;

typedef struct _hash_table {
    uint32_t size;
    hashfunction *hash;
    entry **elements;
} hash_table;


hash_table *hash_table_create(uint32_t size, hashfunction *hf);
void hash_table_destroy(hash_table *ht);
void hash_table_print(hash_table *ht);
bool hash_table_insert(hash_table *ht, const char *key, size_t keylen, void *obj);
void *hash_table_lookup(hash_table *ht, const char *key, size_t keylen);
void *hash_table_delete(hash_table *ht, const char *key, size_t keylen);