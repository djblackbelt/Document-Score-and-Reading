#include "word.h"
#include <string>
#include <iostream>

void step1(string &word){
    
	if (word[0] == '\''){
		word.erase(0,1);
	}
	
	else if (word.size() > 3){
		if (word.substr(word.size()-3, 3) == "'s'"){
			word.erase(word.size()-3, 3);
		}	
	}
	
	else if (word.size() > 2){
		if (word.substr(word.size()-2, 2) == "'s"){
			word.erase(word.size()-2, 2);
		}	
	}
	
	else if (word.size() > 1){
		if (word[word.size()-1] == '\''){
			word.erase(word.size()-1, 1);
		}
	}
	
	step2(word);
}

void step2(string &word){
    
	if (word.size() > 4 && word.substr(word.size()-4, 4) == "sses"){
		word = word.erase(word.size()-4, 4); //check if need =
		word += "ss";
	}
	
	else if (word.size() > 3 && (word.substr(word.size()-3, 3) == "ied" ||
		word.substr(word.size()-3, 3) == "ies")){
		if (preceder(word, word.size()-4).size() > 1){
			word = word.erase(word.size()-3, 3);
			word += "i";
		}
		else{
			word = word.erase(word.size()-3, 3);
			word += "ie";
		}
	}
	
	else if (word.size() > 2 && word.substr(word.size()-2, 2) == "us"){
	//nothing
	}
	else if (word.size() > 2 && word.substr(word.size()-2, 2) == "ss"){
	//nothing
	}
	
	else if (word.size() > 1 && word[word.size()-1] == 's'){
		string pre = preceder(word, word.size()-2);
		for (size_t i = 1; i < pre.size(); i++){
			if (Vowel(pre, i) ==  true){
				word.erase(word.size()-1, 1);
                break;
			}
			else{
                continue;
            }
		}
	}
	step3(word);
}

void step3(string &word){
    
	string r1 = Region1(word);
	if (word.size() > 5 && word.substr(word.size()-5, 5) == "eedly"){
		if (r1.find("eedly") != string::npos){
			word.erase(word.size()-5, 5);
			word += "ee";
		}
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "ingly"){
		string pre = preceder(word, word.size()-6);
		for (size_t i = 0; i < pre.size(); i++){
			if (Vowel(pre, i) == true){
				word.erase(word.size()-5, 5);
				if (pre.substr(pre.size()-2,2) == "at" || pre.substr(pre.size()-2,2) == "bl" || 
				pre.substr(pre.size()-2,2) == "iz"){
					word+="e";
					break;
				}
				else if (pre[pre.size()-1] == pre[pre.size()-2]){
					word.erase(word.size()-1,1);
					break;
				}
				else if (shortWord(pre) == true){
					word += "e";
					break;
				}
				else{
					break;
				}
			}	
		}	
	}		
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "edly"){
	string pre = preceder(word, word.size()-5);
		for (size_t i = 0; i < pre.size(); i++){
			if (Vowel(pre, i) == true){
				word.erase(word.size()-4, 4);
				if (pre.substr(pre.size()-2,2) == "at" || pre.substr(pre.size()-2,2) == "bl" || 
				pre.substr(pre.size()-2,2) == "iz"){
					word+="e";
					break;
				}
			else if (pre[pre.size()-1] == pre[pre.size()-2]){
				word.erase(word.size()-1,1);
				break;
			}
			else if (shortWord(pre) == true){
				word += "e";
				break;
			}
			else{
				break;
				}
			}
		}
	}	
	
	else if (word.size() > 3 && word.substr(word.size()-3, 3) == "eed"){
		if (r1.find("eed") != string::npos){
			word.erase(word.size()-3, 3);
			word += "ee";
		}
	}
	else if (word.size() > 3 && word.substr(word.size()-3, 3) == "ing"){
		string pre = preceder(word, word.size()-4);
		for (size_t i = 0; i < pre.size(); i++){
			if (Vowel(pre, i) == true){
				word.erase(word.size()-3, 3);
				if (pre.substr(pre.size()-2,2) == "at" || pre.substr(pre.size()-2,2) == "bl" || 
				pre.substr(pre.size()-2,2) == "iz"){
					word+="e";
					break;
				}
				else if (pre[pre.size()-1] == pre[pre.size()-2]){
					word.erase(word.size()-1,1);
					break;
				}
				else if (shortWord(pre) == true){
					word += "e";
					break;
				}
				else{
					break;
				}
			}	
		}
	}
	else if (word.size() > 2 && word.substr(word.size()-2, 2) == "ed"){
	string pre = preceder(word, word.size()-3);
		for (size_t i = 0; i < pre.size(); i++){
			if (Vowel(pre, i) == true){
				word.erase(word.size()-2, 2);
				if (pre.substr(pre.size()-2,2) == "at" || pre.substr(pre.size()-2,2) == "bl" || 
				pre.substr(pre.size()-2,2) == "iz"){
					word+="e";
					break;
				}
				else if (pre[pre.size()-1] == pre[pre.size()-2]){
					word.erase(word.size()-1,1);
					break;
				}
				else if (shortWord(pre) == true){
					word += "e";
					break;
				}
				else{
					break;
				}
			}
		}
	}	
	step4(word);
}

void step4(string &word){
    
	if (word.size() > 1){//study
		char c = word[word.size()-2];
		if (word[word.size()-1] == 'y' && Consanant(word, word.size()-2) ==  true && 
		word.substr(1, word.size()-2).find(c) != string::npos ){
			word.erase(word.size()-1, 1);
			word += "i";
		}
	}
	step5(word);
}

void step5(string &word){
	if (word.size() > 7 && word.substr(word.size()-7, 7) == "ization"){
		word.erase(word.size()-7, 7);
		word+="ize";
	}
	else if (word.size() > 7 && word.substr(word.size()-7, 7) == "ational"){
		word.erase(word.size()-7, 7);
		word+="ate";
	}
	else if (word.size() > 7 && word.substr(word.size()-7, 7) == "ousness"){
		word.erase(word.size()-7, 7);
		word+="ous";
	}
	else if (word.size() > 7 && word.substr(word.size()-7, 7) == "iveness"){
		word.erase(word.size()-7, 7);
		word+="ive";
	}
	else if (word.size() > 7 && word.substr(word.size()-7, 7) == "fulness"){
		word.erase(word.size()-7, 7);
		word+="ful";
	}
	
	else if (word.size() > 6 && word.substr(word.size()-6, 6) == "tional"){ //leak
		word.erase(word.size()-6, 6);
		word+="tion";
	}
	else if (word.size() > 6 && word.substr(word.size()-6, 6) == "biliti"){
		word.erase(word.size()-6, 6);
		word+="ble";
	}
	else if (word.size() > 6 && word.substr(word.size()-6, 6) == "lessli"){
		word.erase(word.size()-6, 6);
		word+="less";
	}
	
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "entli"){
		word.erase(word.size()-5, 5);
		word+="ent";
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "ation"){
		word.erase(word.size()-5, 5);
		word+="ate";
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "alism"){
		word.erase(word.size()-5, 5);
		word+="al";
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "aliti"){
		word.erase(word.size()-5, 5);
		word+="al";
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "ousli"){
		word.erase(word.size()-5, 5);
		word+="ous";
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "iviti"){
		word.erase(word.size()-5, 5);
		word+="ive";
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "fulli"){
		word.erase(word.size()-5, 5);
		word+="ful";
	}
	
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "enci"){
		word.erase(word.size()-4, 4);
		word+="ence";
	}
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "anci"){
		word.erase(word.size()-4, 4);
		word+="ance";
	}
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "abli"){
		word.erase(word.size()-4, 4);
		word+="able";
	}
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "izer"){
		word.erase(word.size()-4, 4);
		word+="ize";
	}
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "ator"){
		word.erase(word.size()-4, 4);
		word+="ate";
	}
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "alli"){
		word.erase(word.size()-4, 4);
		word+="al";
	}
	
	else if (word.size() > 3 && word.substr(word.size()-3, 3) == "bli"){
		word.erase(word.size()-3, 3);
		word+="ble";
	}
	else if (word.size() > 3 && word.substr(word.size()-3, 3) == "ogi"){
		if (word[word.size()-4] == 'l'){
			word.erase(word.size()-3, 3);
			word+="og";
			}
		}
		
	else if (word.size() > 2 && word.substr(word.size()-2, 2) == "li"){
		string pre = preceder(word, word.size()-3);
		if (liEnding(pre) == true){
			word.erase(word.size()-2, 2);
		}
	}
	step6(word);
}

void step6(string &word){
	string r1 = Region1(word);
	string r2 = Region1(r1);
	if (word.size() > 7 && word.substr(word.size()-7, 7) == "ational"){
		if (r1.find("ational") != string::npos){
			word.erase(word.size()-7, 7);
			word += "ate";
		}
	}
	
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "alize"){
		if (r1.find("alize") != string::npos){
			word.erase(word.size()-5, 5);
			word += "al";
		}
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "icate"){
		if (r1.find("icate") != string::npos){
			word.erase(word.size()-5, 5);
			word += "ic";
		}
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "iciti"){
		if (r1.find("iciti") != string::npos){
			word.erase(word.size()-5, 5);
			word += "ic";
		}
	}
	else if (word.size() > 5 && word.substr(word.size()-5, 5) == "ative"){
		if (r2.find("ative") != string::npos){
			word.erase(word.size()-5, 5);
		}
	}
	
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "tional"){
		if (r1.find("tional") != string::npos){
			word.erase(word.size()-4, 4);
			word += "tion";
		}
	}	
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "ical"){
		if (r1.find("ical") != string::npos){
			word.erase(word.size()-4, 4);
			word += "ic";
		}
	
	}
	else if (word.size() > 4 && word.substr(word.size()-4, 4) == "ness"){
		if (r1.find("ness") != string::npos){
			word.erase(word.size()-4, 4);
		}
	}
	
	else if (word.size() > 3 && word.substr(word.size()-3, 3) == "ful"){
		if (r1.find("ful") != string::npos){
			word.erase(word.size()-3, 3);
		}
	}	
	step7(word);
}

void step7(string &word){
	string r1 = Region1(word);
	string r2 = Region2(word);
	if (word.size() > 5 && word.substr(word.size()-5, 5) == "ement"){
		if (r2.find(word.substr(word.size()-5, 5)) != string::npos){
				word.erase(word.size()-5, 5);
		}
	}
	
	else if (word.size() > 4 && (word.substr(word.size()-4, 4) == "ance" ||
	word.substr(word.size()-4, 4) == "ence" ||
	word.substr(word.size()-4, 4) == "able" ||
	word.substr(word.size()-4, 4) == "ible" ||
	word.substr(word.size()-4, 4) == "ment")){
		if (r2.find(word.substr(word.size()-4, 4)) != string::npos){
			word.erase(word.size()-4, 4);
		}
	}
	//conspicuous
	else if (word.size() > 3 && (word.substr(word.size()-3, 3) == "ent" ||
		word.substr(word.size()-3, 3) == "ism" ||
		word.substr(word.size()-3, 3) == "ate" ||
		word.substr(word.size()-3, 3) == "iti" ||
		word.substr(word.size()-3, 3) == "ous" ||
		word.substr(word.size()-3, 3) == "ive" ||
		word.substr(word.size()-3, 3) == "ize" ||
		word.substr(word.size()-3, 3) == "ant")){
			if (r2.find(word.substr(word.size()-3, 3)) != string::npos){
				word.erase(word.size()-3, 3);
			}
	}
	
	else if (word.size() > 3 && word.substr(word.size()-3, 3) == "ion"){
		if ( r2.find("ion") != string::npos && (word[word.size()-4] == 's' || word[word.size()-4] == 't')){
			word.erase(word.size()-3, 3);
		}
	}
	
	else if (word.size() > 2 && (word.substr(word.size()-2, 2) == "al" ||
		word.substr(word.size()-2, 2) == "er" ||
		word.substr(word.size()-2, 2) == "ic")){
			if (r2.find(word.substr(word.size()-2, 2)) != string::npos){
				word.erase(word.size()-2, 2);
			}
	}		
	
	step8(word);
}

void step8(string &word){
	string r1 = Region1(word);
	string r2 = Region2(word);
    string pre = preceder(word, word.size()-2);
    if (r1.size() > 1 || r2.size() > 2){
        if (word.size() > 1 && word[word.size()-1] == 'e'){
            if ( (r2.find('e') != string::npos) || (r1.find('e') != string::npos && shortSyl(pre) == false ) ){
                word.erase(word.size()-1, 1);
            }
        }
        else if (word.size() > 1 && word[word.size()-1] == 'l'){
            if ( (r2.find('l') != string::npos) && (word.substr(word.size()-2, 2) == "ll") ){
                word.erase(word.size()-1, 1);
            }
        }
    }
}

bool Vowel(string s, size_t i){
	if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
		return true;
	}
	if (s[i] == 'y' && i == 0){
		return true;
	}
	if (s[i] == 'y' && Consanant(s, i-1) == true){
		return true;
	}
	return false;
}

bool Consanant(string s, size_t i){
	if (Vowel(s,i) == false){
		return true;
	}
	return false;
}

string Region1(string s){
	if (s.size() > 3){
		for (size_t i=0; i < s.size(); i++){
			if (i < s.size()-1 && Vowel(s, i) == true && Consanant(s, i+1) == true){
				return s.substr(i+2, string::npos);
			}
		}
	}
	return "";
}

string Region2(string s){
	return Region1(Region1(s));
}

bool shortSyl(string s){
	if (s.size() == 2 && Vowel(s,0) == true && Consanant(s,1) == true){
		return true;
	}
	if (Consanant(s, s.size()-3) == true && Vowel(s, s.size()-3) == true && Consanant(s, s.size()-1)
		&& (s[s.size()-1] != 'w' && s[s.size()-1] != 'x' && s[s.size()-1] != 'y') ){
			return true;
		}
		return false;
}

bool shortWord(string s){
	if (shortSyl(s) == true && Region1(s) == ""){
		return true;
	}
	return false;
}

string preceder(string s, size_t i){
	return s.substr(0,i+1);
}

bool liEnding(string s){
	if (s[s.size()-1] == 'c' || s[s.size()-1] == 'd' || s[s.size()-1] == 'e' || s[s.size()-1] == 'g' || 
	s[s.size()-1] == 'h' || s[s.size()-1] == 'k' || s[s.size()-1] == 'm' || s[s.size()-1] == 'n' || 
	s[s.size()-1] == 'r' || s[s.size()-1] == 't'){
		return true;
	}
	return false;
}
