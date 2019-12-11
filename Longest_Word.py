""" Find longest word in dictionary that is a subsequence of a given string.
    Given a string S and a set of words D, find the longest word in D that
    is a subsequence of S.

    Word W is a subsequence of S if some number of characters, possibly zero,
    can be deleted from S to form W, without reordering the remaining
    characters. """

w = ""
s = "abppplee"
d = ["able", "ale", "apple", "bale", "kangaroo"]


def r_longest(s, d, r_word ='', s_ix =0, d_ix=0):
    """ This is a recursive function that returns a word that can be created
        from a given string S and the word is found in dictionary D. """
    if len(s) == 0 or len(d) == 0:
        return r_word
    
    #print(r_word, "i: ")
    if s[s_ix] == d[d_ix]:
        r_word += d[d_ix]
        #print(r_word)
        return r_longest(s[s_ix + 1:], d[d_ix + 1:], r_word, s_ix, d_ix)

    return r_longest(s[s_ix+1:], d, r_word, s_ix, d_ix)


def longest_wrapper(s, d, w):
    """ This is a wrapper function for the recursive function called longest.
        This function will pass the string S, dictionary D, and return word W,
        where W is the longest word found in D, created from a subset of S. """
    new_word = ''
    for i in range(len(d)):
        new_word = r_longest(s, d[i])

        if len(new_word) > len(w):
            w = new_word

    return w


def i_longest(s, d, w):
    """ While loop to iterate through all letters in s and all letters in d.
        Notice that this avoids the inner for-loops or the O(N^2), rather,
        this optimization has a running time of O(N*S).
        Note: inspired on a stack data structure with a Greedy Algorithm. """

    """ Creating helper variables, such as indexes and flags """
    new_word = ''
    finished = False
    d_idx = s_idx = w_idx = 0

    while finished == False:
        word = d[d_idx]
        
        if word[w_idx] == s[s_idx]: #Matching criteria for subset letters to word
                new_word += word[w_idx]
                s_idx += 1
                w_idx += 1
                #print("1.- 1st s_idx: ", s_idx, "\tw_idx: ", w_idx, "New_word: ", new_word)

        else: #No match found, increase the s index
                s_idx +=1
                #print("2.- Else s_idx: ", s_idx, "\tw_idx: ", w_idx, "New_word: ", new_word)

        if s_idx >= len(s) or w_idx >= len(word): #We finished checking all the word
                d_idx += 1
                s_idx = w_idx = 0

                if len(new_word) > len(w): #Assign the longest word to w
                    w = new_word
                    
                #print("new_word\t", new_word, "\tWord\t", w)
                new_word = ''
                
        if d_idx >= len(d): #Exiting critereon, d is empty
            finished = True

    return w
