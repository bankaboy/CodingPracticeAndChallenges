/* 
Problem Statement - 

HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.

The special characters and their entities for HTML are:

* Quotation Mark: the entity is &quot; and symbol character is ".
* Single Quote Mark: the entity is &apos; and symbol character is '.
* Ampersand: the entity is &amp; and symbol character is &.
* Greater Than Sign: the entity is &gt; and symbol character is >.
* Less Than Sign: the entity is &lt; and symbol character is <.
* Slash: the entity is &frasl; and symbol character is /.
Given the input text string to the HTML parser, you have to 
implement the entity parser.

Return the text after replacing the entities by the special
characters.

Example 1:
Input: text = "&amp; is an HTML entity but &ambassador; is not."
Output: "& is an HTML entity but &ambassador; is not."
Explanation: The parser will replace the &amp; entity by &

Example 2:
Input: text = "and I quote: &quot;...&quot;"
Output: "and I quote: \"...\""

Example 3:
Input: text = "Stay home! Practice on Leetcode :)"
Output: "Stay home! Practice on Leetcode :)"

Example 4:
Input: text = "x &gt; y &amp;&amp; x &lt; y is always false"
Output: "x > y && x < y is always false"

Example 5:
Input: text = "leetcode.com&frasl;problemset&frasl;all"
Output: "leetcode.com/problemset/all"

Constraints:

* 1 <= text.length <= 10^5
* The string may contain any possible characters out of all the 256 
ASCII characters.
*/

// My solution - did not work
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string entityParser(string text) {
        string quote = "\"";
        string squot = "\'";
        string lt = "<";
        string gt = ">";
        string amp = "&";
        string slash = "/";
        while (true) {
            cout<<text<<endl;
            if (text.find("&quot;") != string::npos) {
                size_t found = text.find("&quot;");
                text.replace(found,found+6,quote);
            }
            else if (text.find("&apos;") != string::npos) {
                size_t found = text.find("&apos;");
                text.replace(found,found+6,squot);
            }
            else if (text.find("&amp;") != string::npos) {
                size_t found = text.find("&amp;");
                text.replace(found,found+5,amp);
            }
            else if (text.find("&gt;") != string::npos) {
                size_t found = text.find("&gt;");
                text.replace(found,found+4,gt);
            }
            else if (text.find("&lt;") != string::npos) {
                size_t found = text.find("&lt;");
                text.replace(found,found+4,lt);
            }
            else if (text.find("&frasl;") != string::npos) {
                size_t found = text.find("&frasl;");
                text.replace(found,found+7,slash);
            }
            else 
                break;
        }
        return text;
    }
};

// Discussion 

class Solution {
public:
    string entityParser(string text)
    {
        unordered_map<string,string> m;
        m["&quot;"]="\"";
        m["&apos;"]="'";
        m["&amp;"]="&";
        m["&gt;"]=">";
        m["&lt;"]="<";
        m["&frasl;"]="/";
        string ans;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]=='&')
            {
                string s;
                while(i<text.size())
                {
                    s+=text[i];
                    
                    if((text[i]==';')&&m.find(s)!=m.end())
                    {
                        ans+=m[s];
                        s="";
                        break;
                    }
                    else i++;
                    if(text[i]=='&')
                    {
                        i--;
                        break;
                    }
                }
                ans+=s;
            }
            else
            {
                ans+=text[i];
            }
        }
        return ans;
    }
};