type TrieNode struct {
	IsLeaf   bool
	children []*TrieNode
}

func (tn *TrieNode) Insert(word string) {
	curr := tn
	for _, c := range word {
		code := c - 'a'
		nxt := curr.children[code]
		if nxt == nil {
			curr.children[code] = &TrieNode{false, make([]*TrieNode, 26)}
			nxt = curr.children[code]
		}
		curr = nxt
	}
	curr.IsLeaf = true
}

func (tn *TrieNode) ShortestRoot(word string) string {
	curr := tn
	for i, c := range word {
		curr = curr.children[c-'a']
		if curr == nil {
			return word
		}
		if curr.IsLeaf {
			return word[:i+1]
		}
	}
	return word
}

func replaceWords(dictionary []string, sentence string) string {
	ret, root, words := make([]string, 0), &TrieNode{false, make([]*TrieNode, 26)}, strings.Split(sentence, " ")
	for _, word := range dictionary {
		root.Insert(word)
	}
	for _, word := range words {
		ret = append(ret, root.ShortestRoot(word))
	}
	return strings.Join(ret, " ")
}