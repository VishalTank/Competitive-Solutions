int main() {

    int n, q;
    cin>>n>>q;
    cin.ignore();

    map <string, string> attr_pair;
    string input, tag_preamble = "";

    for (int i=0;i<n;i++) {
        getline(cin, input);

        stringstream ss(input);
        string word, attribute, value;
        size_t pos;

        while(getline(ss, word, ' ')) {
            if(word[0] == '<') {

                string tag;

                if (word[1] == '/') {
                    tag = word.substr(2);
                    tag = tag.substr(0, tag.length() - 1);
                    pos = tag_preamble.find("." + tag);

                    if (pos == string::npos)
                        tag_preamble = "";
                    else
                        tag_preamble = tag_preamble.substr(0, pos);
                } else {
                    tag = word.substr(1);

                    if (tag.find(">") != string::npos)
                        tag = tag.substr(0, tag.length() - 1);

                    if (tag_preamble == "")
                        tag_preamble = tag;
                    else
                        tag_preamble = tag_preamble + "." + tag;
                }
            }
            else if(word[0] == '"') {
                pos = word.find_last_of('"');
                value = word.substr(1, pos - 1);
                attr_pair[attribute] = value;
            }
            else if (word[0] != '=')
                attribute = tag_preamble + "~" + word;
        }
    }

    for (int i = 0; i < q; i++) {
        getline(cin, input);
        if (attr_pair.find(input) == attr_pair.end())
            cout << "Not Found!" << endl;
        else
            cout << attr_pair[input] << endl;
    }
}