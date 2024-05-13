// https://blog.naver.com/amainlog/221408352878

typedef struct {
    char *key;
    void* value;
} KVPair;

typedef struct Dictionary_t {
    KVPair *head;
    struct Dictionary_t *tail;
} Dictionary;

Dictionary* dict_new();
void dict_show(Dictionary *dictionary);
void dict_add(Dictionary *dictionary, const char *key, void* value);
int dict_has(Dictionary *dictionary, const char *key);
void* dict_get(Dictionary *dictionary, const char *key);
void dict_remove(Dictionary *dictionary, const char *key);
void dict_free(Dictionary *dictionary);
