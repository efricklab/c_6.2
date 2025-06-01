## ✅ 6.2 Lab – Using Strings in C (GitHub Codespaces Edition)

---

### **Introduction**

Strings in C are arrays of characters terminated with a null character (`\0`). The standard C library provides many functions to manipulate and analyze strings. This lab is divided into two parts:

* **Part 1** introduces basic operations such as input, copying, concatenation, and comparison.
* **Part 2** explores more advanced functions like searching within strings, reversing strings, and tokenizing them into words.

---

### **Objectives**

By the end of this lab, you will:

* Read and manipulate strings using character arrays.
* Use standard functions from `<string.h>`.
* Search for characters or substrings.
* Reverse strings manually.
* Tokenize a string into words using `strtok`.

---

## 🧪 **Part 1: Basic String Operations**

---

### **Step 1: Create `strings.c` in GitHub Codespaces**

1. Open your GitHub Codespace.
2. In the Explorer pane, click **New File** and name it: `strings.c`
3. Paste the following code:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    char greeting[100];
    char compareStr[50] = "Hello";

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline from fgets

    strcpy(greeting, "Hello, ");
    strcat(greeting, name);

    printf("\n%s!\n", greeting);
    printf("The greeting has %lu characters.\n", strlen(greeting));

    if (strncmp(greeting, compareStr, 5) == 0) {
        printf("The greeting starts with 'Hello'.\n");
    } else {
        printf("The greeting does not start with 'Hello'.\n");
    }

    return 0;
}
```

---

### **Step 2: Compile and Run**

```bash
gcc strings.c -o strings
./strings
```

✅ You should see a personalized greeting, length info, and a check for the word "Hello".

---

## 🧪 **Part 2: Advanced String Functions**

---

### **Step 3: Extend the Program with More Functions**

Below your existing `main()` code, add this block:

```c
    // Part 2: Search for a character
    char *foundChar = strchr(name, 'a');
    if (foundChar) {
        printf("The letter 'a' was found in your name at position: %ld\n", foundChar - name);
    } else {
        printf("The letter 'a' was not found in your name.\n");
    }

    // Search for a substring
    if (strstr(greeting, name)) {
        printf("Your name appears in the greeting.\n");
    }

    // Reverse the name manually
    int len = strlen(name);
    char reversed[50];
    for (int i = 0; i < len; i++) {
        reversed[i] = name[len - 1 - i];
    }
    reversed[len] = '\0';

    printf("Your name reversed is: %s\n", reversed);

    // Tokenize a sentence
    char sentence[100] = "C is a powerful programming language";
    printf("\nOriginal sentence: %s\n", sentence);
    printf("Words in the sentence:\n");
    
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        printf("- %s\n", token);
        token = strtok(NULL, " ");
    }
```

---

### **Step 4: Recompile and Run Again**

```bash
gcc strings.c -o strings
./strings
```

**Sample Output:**

```
Enter your name: Alice

Hello, Alice!
The greeting has 13 characters.
The greeting starts with 'Hello'.
The letter 'a' was not found in your name.
Your name appears in the greeting.
Your name reversed is: ecilA

Original sentence: C is a powerful programming language
Words in the sentence:
- C
- is
- a
- powerful
- programming
- language
```

---

### **Summary**

In this lab, you learned to:

* Work with strings using character arrays.
* Use `fgets`, `strcpy`, `strcat`, `strlen`, `strncmp`.
* Search strings with `strchr` and `strstr`.
* Reverse a string manually.
* Tokenize a sentence into individual words with `strtok`.
