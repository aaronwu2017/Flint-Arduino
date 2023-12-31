#include <stdio.h>
#include "lv_keyboard_seed.h"
#include "../../../../../uBitcoin/src/utility/trezor/bip39_english.h"
#include "../../../../../../Flint/Trie.h"
#if LV_USE_BTNMATRIX
static TrieNode *myTrie = NULL;
static TrieNode *currentNode = NULL;
static int letterTobtnm_mapIndex[26] = {10, 24, 22, 12, 2, 13, 14, 15, 7, 16, 17, 18, 26, 25, 8, 9, 0, 3, 11, 4, 6, 23, 1, 21, 5, 20};
void btnm_event_handler1(lv_event_t * e) {
char strtest[12];
TrieNode *testNode = NULL;
lv_event_code_t code = lv_event_get_code(e);
lv_obj_t * obj = lv_event_get_target(e);
uint16_t btn_id = lv_btnmatrix_get_selected_btn(obj);
const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
lv_obj_t * ta = lv_event_get_user_data(e);
int index = txt[0] - 'a';
const char * fullEnteredText = lv_textarea_get_text(ta) ;

    if (myTrie == NULL) {
        myTrie = createNode(0);  
        for (int i = 0; i < 2048; i++) {
            insert(myTrie, wordlist[i]);  // Insert words into the trie
           
        }
        currentNode = myTrie;
   
    }
    myTrie->parent = NULL;
    if (strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) {
        
        if(currentNode->parent == NULL){
            const char *lastSpace = strrchr(fullEnteredText, ' ');
            if (lastSpace != NULL) {
                const char *lastWord = fullEnteredText;
                for (const char *p = lastSpace - 1; p > fullEnteredText; --p) {
                    if ( *(p - 1) == ' '&&*p != ' ') {
                        lastWord = p;
                        break;
                    }
                }
               
            // const char *lastWord =  lastSpace-8;
                for (const char *p = lastWord; p <= lastSpace; p++) {
                  if (*p == ' ') {
                        lv_textarea_del_char(ta);
                    } else{
                        int lastWordLetterIndex = *p - 'a';
                        currentNode = currentNode->children[lastWordLetterIndex];
                    }                 
                }
            }else{
           //no text on the textarea
                return;    
            }

        }
        currentNode = currentNode->parent;
        lv_textarea_del_char(ta);
        for (int horizontalIndex = 0; horizontalIndex < 26; horizontalIndex++) {

            lv_btnmatrix_clear_btn_ctrl(obj, letterTobtnm_mapIndex[horizontalIndex], LV_BTNMATRIX_CTRL_HIDDEN);
            if (currentNode->children[horizontalIndex] == NULL) {

                lv_btnmatrix_set_btn_ctrl(obj, letterTobtnm_mapIndex[horizontalIndex], LV_BTNMATRIX_CTRL_HIDDEN);
            }
        }
        return;
    }

    if (currentNode && currentNode->children[index] != NULL) {
        currentNode = currentNode->children[index];
    }

    for (int i = 0; i < 26; i++) {
        lv_btnmatrix_clear_btn_ctrl(obj, letterTobtnm_mapIndex[i], LV_BTNMATRIX_CTRL_HIDDEN);
    }
    lv_textarea_add_text(ta, txt);
    if (currentNode->isEndOfWord == 1) {

              lv_textarea_add_text(ta, " ");
            //    sprintf(strtest, "%d", (9-currentNode->level));
                lv_textarea_add_text(ta, strtest);
        // for(int j = 0;j<9-currentNode->level;j++){
        //     lv_textarea_add_text(ta, " ");
        // }
                currentNode = myTrie;
    } else{
        for (int horizontalIndex = 0; horizontalIndex < 26; horizontalIndex++) {
                if (currentNode->children[horizontalIndex] == NULL) {
                    lv_btnmatrix_set_btn_ctrl(obj, letterTobtnm_mapIndex[horizontalIndex], LV_BTNMATRIX_CTRL_HIDDEN);
                }
        } 
    }
    if(currentNode == myTrie){
         //disable x  as bip39 word list doesnot have word starting with x
       lv_btnmatrix_set_btn_ctrl(obj, letterTobtnm_mapIndex[23], LV_BTNMATRIX_CTRL_HIDDEN);
    }
}


static const char * btnm_map[] = {"q", "w", "e", "r", "t", "y","u","i", "o","p","\n",
                                  "a", "s", "d", "f", "g","h","j","k","l", "\n",
                                  LV_SYMBOL_BACKSPACE,"z", "x", "c", "v", "b","n","m","go",""
                                   };

lv_obj_t * lv_ex_btnmatrix_1(lv_obj_t * obj)
{
    

    lv_obj_t * btnm1 = lv_btnmatrix_create(obj);
   lv_btnmatrix_set_map(btnm1, btnm_map);

    lv_btnmatrix_set_btn_ctrl(btnm1, 27, LV_BTNMATRIX_CTRL_CHECKED);
    lv_obj_align(btnm1, LV_ALIGN_CENTER, 0, 0);

     return btnm1;
}

#endif