#include "D:/Documents/SourceTree/Challenges/C++/CLion/DMOJ/tasks/CCC16S3.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
    std::string input;
    std::string output;
    bool active;
    bool has_output;
};

bool check(std::string expected, std::string actual) {
    while(!expected.empty() && isspace(*--expected.end()))
        expected.erase(--expected.end());
    while(!actual.empty() && isspace(*--actual.end()))
        actual.erase(--actual.end());
    return expected == actual;
}

} // namespace jhelper

int main() {
    std::vector<jhelper::Test> tests = {
        {"8 2\n5 2\n0 1\n0 2\n2 3\n4 3\n6 1\n1 5\n7 3", "3", true, true},{"8 5\n0 6 4 3 7\n0 1\n0 2\n2 3\n4 3\n6 1\n1 5\n7 3", "7", true, true},{"100 2\n92 44\n13 34\n33 8\n86 51\n9 39\n80 62\n96 12\n43 63\n32 45\n95 49\n3 47\n95 74\n15 50\n80 68\n50 30\n46 89\n6 69\n36 67\n54 52\n68 8\n32 85\n19 36\n62 42\n43 88\n14 4\n60 83\n54 82\n68 70\n3 60\n29 16\n71 19\n55 87\n28 87\n29 1\n64 92\n67 14\n21 41\n84 79\n83 13\n28 90\n7 10\n4 21\n20 38\n31 85\n73 75\n25 97\n2 17\n45 11\n23 92\n57 90\n22 45\n56 6\n98 64\n72 55\n52 84\n81 44\n63 98\n93 95\n94 27\n35 1\n69 75\n55 73\n11 78\n46 59\n24 66\n10 79\n31 89\n9 78\n30 65\n88 56\n53 77\n16 0\n7 62\n23 97\n53 82\n33 18\n76 99\n15 27\n24 93\n51 77\n35 37\n40 41\n39 86\n66 0\n38 48\n27 1\n47 46\n73 61\n65 25\n76 44\n99 91\n44 12\n58 91\n87 5\n49 58\n96 2\n48 64\n33 2\n57 41\n26 97", "22", true, true},{"79 6\n62 72 53 28 39 7\n77 41\n46 25\n64 39\n28 17\n34 57\n36 12\n48 13\n32 53\n33 72\n70 6\n42 14\n27 34\n66 75\n49 54\n23 9\n45 58\n40 39\n48 63\n72 29\n51 38\n7 50\n11 26\n52 33\n12 0\n3 1\n65 46\n5 33\n39 56\n64 17\n21 75\n48 33\n75 14\n3 11\n30 53\n75 4\n56 55\n2 8\n31 4\n1 68\n62 6\n3 63\n25 67\n53 44\n61 75\n16 68\n62 15\n50 24\n12 57\n41 61\n12 25\n73 33\n14 36\n2 23\n74 18\n17 30\n78 71\n2 38\n39 35\n6 49\n61 76\n12 69\n14 74\n74 37\n19 34\n68 62\n45 22\n58 13\n24 40\n14 43\n21 60\n78 10\n74 50\n8 55\n76 10\n9 47\n59 69\n73 20\n8 63", "28", true, true},{"990 500\n362 228 481 320 500 879 453 473 238 91 432 777 631 423 852 278 808 522 738 25 369 821 758 737 882 931 866 111 638 746 917 13 383 848 612 136 988 872 875 458 335 713 629 409 672 126 1 578 902 594 114 766 952 906 687 512 55 651 957 844 962 382 842 152 971 352 223 462 825 827 929 58 558 348 400 414 289 86 39 576 593 884 163 376 877 511 4 0 71 113 900 12 60 411 754 29 652 8 935 153 693 371 619 524 314 217 32 148 655 90 582 707 600 407 85 252 308 23 424 50 782 479 501 270 936 301 446 668 545 287 735 726 813 10 93 930 741 654 343 143 215 459 640 823 191 886 378 505 200 643 323 478 408 290 41 20 309 379 507 351 355 589 98 705 708 405 393 48 235 897 964 169 835 61 288 286 616 728 789 418 572 160 669 606 943 117 585 14 784 415 538 310 52 104 733 127 5 280 969 771 476 266 980 698 75 797 155 748 829 676 284 210 633 498 192 186 434 926 229 232 30 141 948 622 571 331 914 219 337 103 514 172 47 753 503 78 603 591 489 281 112 893 454 628 536 282 830 283 231 358 641 605 483 800 583 859 199 209 107 599 517 846 762 690 977 218 455 196 817 206 824 486 494 321 135 542 812 497 319 539 177 447 584 154 205 439 597 42 934 609 899 760 375 54 427 801 774 457 258 80 247 712 17 406 158 444 360 736 870 179 298 734 602 326 94 442 441 193 340 168 133 709 896 615 422 577 946 324 120 796 878 49 573 237 33 873 347 520 307 303 611 725 883 285 963 697 561 778 175 327 773 907 833 985 482 549 636 974 715 365 70 965 614 814 864 317 180 467 262 533 526 40 445 395 794 88 403 402 892 302 354 268 580 472 623 683 516 894 178 465 227 242 747 939 541 710 534 277 809 334 100 933 532 874 751 38 129 165 529 428 851 547 521 220 183 515 267 979 788 876 798 910 648 216 269 820 905 679 449 456 213 26 911 610 620 843 564 986 684 99 95 194 212 925 880 837 976 510 361 811 810 74 475 660 551 598 157 869 718 119 140 264 649 244 43 772 176 706 983 204 785 945 575 840 82 913 89 938 224 724 67 142 437 381 841 353 316 818 853 749 46 723 901 924 673 531 688 477 863 291\n646 81\n959 650\n596 754\n672 813\n914 446\n332 297\n731 533\n466 790\n581 987\n920 550\n76 91\n356 833\n33 111\n774 288\n481 248\n155 493\n959 939\n255 276\n216 526\n141 42\n616 224\n710 470\n9 708\n10 508\n867 534\n178 879\n513 422\n909 759\n122 600\n423 981\n68 538\n680 755\n166 724\n984 769\n742 755\n573 26\n984 391\n396 594\n162 433\n508 282\n903 376\n449 601\n366 39\n495 681\n118 737\n152 126\n216 636\n546 629\n269 799\n530 488\n13 483\n178 257\n77 175\n846 832\n579 233\n22 161\n461 887\n373 467\n902 76\n29 461\n932 152\n50 820\n478 520\n595 157\n493 738\n360 348\n300 154\n106 967\n517 875\n383 249\n560 258\n681 337\n733 961\n102 441\n209 96\n140 358\n300 314\n263 624\n840 556\n725 158\n823 948\n543 355\n209 435\n352 20\n110 594\n87 683\n946 556\n537 730\n787 127\n418 123\n286 548\n974 562\n577 877\n827 384\n191 792\n379 392\n113 202\n190 767\n733 830\n455 931\n746 143\n658 378\n719 917\n575 37\n272 277\n474 94\n664 295\n518 393\n924 689\n465 489\n872 544\n379 57\n794 429\n933 323\n6 3\n653 966\n164 255\n586 333\n899 910\n16 707\n918 530\n662 146\n222 952\n749 599\n612 469\n211 860\n825 921\n377 776\n581 11\n39 521\n298 125\n196 189\n359 613\n72 393\n479 785\n881 238\n636 361\n687 831\n378 942\n405 118\n200 458\n311 413\n559 66\n901 264\n320 95\n84 159\n50 928\n676 328\n689 316\n369 827\n233 587\n445 312\n798 487\n207 721\n559 262\n379 590\n844 754\n898 128\n821 956\n865 243\n104 336\n947 8\n86 442\n3 701\n177 192\n926 793\n475 11\n565 447\n175 242\n252 715\n451 334\n534 59\n642 599\n892 861\n394 729\n10 60\n831 506\n285 796\n949 307\n440 65\n985 873\n400 985\n570 270\n908 273\n986 728\n912 802\n831 137\n962 457\n151 375\n689 472\n448 524\n231 463\n637 678\n857 721\n213 943\n399 303\n188 180\n123 814\n502 278\n663 473\n133 875\n32 890\n660 670\n750 585\n832 735\n812 694\n100 210\n519 823\n505 974\n170 436\n461 43\n790 329\n480 453\n541 519\n912 105\n136 703\n421 902\n771 717\n963 542\n614 230\n284 145\n648 483\n14 109\n130 431\n784 234\n718 555\n780 944\n628 574\n631 782\n97 448\n572 975\n938 97\n919 463\n717 954\n167 264\n414 260\n664 318\n140 229\n908 536\n292 253\n836 889\n550 521\n629 388\n272 716\n224 228\n518 553\n976 182\n267 15\n971 385\n855 920\n149 713\n18 734\n610 37\n927 785\n784 187\n131 394\n49 531\n592 369\n109 450\n204 150\n690 412\n21 756\n105 644\n988 470\n266 503\n471 957\n114 271\n667 122\n982 897\n128 610\n466 285\n873 83\n765 223\n842 586\n557 340\n12 836\n63 397\n694 957\n48 558\n45 789\n443 1\n317 163\n904 165\n719 339\n710 229\n973 291\n135 770\n869 134\n620 766\n145 975\n891 171\n809 248\n829 761\n611 459\n499 700\n801 500\n665 885\n788 700\n866 906\n926 313\n621 681\n533 403\n968 726\n955 842\n86 101\n707 584\n322 770\n332 341\n254 407\n121 195\n962 147\n459 129\n299 566\n247 273\n370 747\n576 196\n90 253\n585 650\n62 860\n311 643\n290 775\n671 151\n592 418\n661 631\n718 828\n434 203\n596 245\n775 958\n711 960\n343 353\n824 205\n3 328\n573 381\n486 777\n284 641\n368 725\n768 747\n18 639\n361 58\n24 330\n764 205\n725 482\n933 384\n381 411\n881 305\n877 185\n119 771\n829 738\n65 388\n746 280\n291 549\n797 630\n91 679\n617 845\n362 259\n849 804\n306 353\n273 85\n729 686\n961 705\n138 305\n308 488\n146 896\n835 871\n908 779\n250 151\n584 781\n608 23\n615 768\n351 108\n15 495\n431 4\n441 469\n46 779\n740 739\n486 73\n227 862\n846 227\n570 595\n101 704\n454 428\n71 753\n677 537\n512 130\n356 251\n941 607\n498 269\n19 262\n685 890\n730 380\n773 899\n952 239\n503 631\n472 340\n720 23\n90 557\n840 75\n759 19\n579 82\n420 838\n76 121\n509 476\n697 901\n358 757\n236 292\n964 181\n132 165\n221 352\n810 745\n485 411\n588 696\n859 501\n113 112\n406 417\n65 61\n734 744\n347 787\n798 55\n706 179\n17 709\n931 894\n320 897\n772 888\n275 534\n852 54\n510 786\n843 515\n692 842\n743 907\n117 783\n805 449\n221 724\n587 142\n929 731\n211 339\n857 92\n84 350\n28 601\n711 30\n51 7\n214 242\n714 331\n206 44\n936 833\n853 297\n693 522\n970 560\n268 77\n868 54\n646 522\n883 838\n115 182\n342 816\n447 220\n988 583\n953 940\n516 805\n943 367\n657 351\n111 143\n244 46\n362 494\n419 848\n389 402\n152 515\n923 884\n880 971\n210 468\n373 752\n301 589\n180 607\n946 255\n73 268\n88 439\n858 757\n566 895\n114 498\n562 795\n745 861\n871 383\n544 907\n89 370\n762 33\n800 805\n2 203\n568 950\n267 894\n922 218\n489 602\n930 435\n743 795\n749 751\n257 107\n760 134\n313 617\n78 511\n364 639\n45 391\n983 548\n404 984\n425 647\n752 326\n960 615\n724 430\n675 634\n141 281\n767 294\n595 878\n12 964\n166 910\n582 905\n351 662\n79 545\n23 307\n9 324\n36 317\n172 38\n659 369\n663 115\n578 49\n815 390\n251 739\n6 736\n789 13\n353 226\n225 384\n750 653\n492 642\n771 69\n298 202\n839 882\n95 974\n678 654\n408 632\n937 439\n701 480\n285 101\n420 528\n977 467\n640 359\n476 914\n606 883\n147 278\n402 832\n377 801\n330 238\n194 214\n539 835\n168 588\n468 452\n394 150\n888 53\n666 318\n409 433\n254 426\n279 938\n98 815\n955 167\n864 561\n737 165\n703 632\n612 758\n771 979\n232 813\n204 232\n734 237\n537 215\n696 71\n326 675\n212 626\n40 205\n256 540\n139 255\n4 858\n555 600\n693 682\n722 568\n38 7\n859 412\n989 509\n523 507\n88 679\n407 889\n46 44\n794 177\n346 577\n414 279\n517 426\n986 231\n886 547\n179 786\n732 475\n826 288\n980 884\n14 638\n142 814\n28 803\n372 357\n207 102\n655 818\n593 358\n504 454\n296 249\n504 691\n336 417\n716 917\n695 794\n376 712\n153 303\n655 481\n953 788\n314 648\n80 863\n163 850\n116 129\n187 25\n763 406\n390 451\n386 902\n667 198\n838 310\n381 899\n197 839\n223 319\n528 289\n661 287\n627 302\n319 25\n40 411\n148 135\n972 52\n852 706\n467 460\n604 900\n438 241\n924 792\n609 230\n493 812\n409 502\n849 776\n608 506\n282 172\n138 176\n317 698\n397 183\n625 571\n271 598\n465 525\n344 293\n563 459\n294 900\n168 484\n981 868\n762 856\n856 315\n948 978\n184 890\n763 66\n969 270\n257 225\n55 892\n566 949\n173 341\n523 539\n680 446\n188 554\n847 745\n678 618\n56 880\n120 307\n473 895\n301 732\n898 315\n213 57\n427 559\n424 808\n215 324\n932 451\n811 800\n401 39\n350 170\n581 855\n440 189\n591 625\n817 80\n637 194\n822 531\n853 802\n8 63\n403 590\n31 230\n909 161\n753 171\n274 437\n870 830\n112 260\n591 936\n442 564\n424 922\n968 723\n499 58\n201 919\n365 934\n368 328\n686 954\n748 764\n117 168\n432 318\n977 471\n444 265\n338 364\n75 304\n22 309\n289 372\n655 192\n173 728\n493 312\n791 120\n327 921\n928 303\n335 382\n474 132\n154 656\n12 535\n325 335\n727 890\n331 365\n212 718\n321 742\n806 24\n96 532\n174 329\n182 543\n68 963\n283 799\n594 834\n609 527\n820 598\n684 580\n51 845\n634 574\n771 127\n265 496\n151 613\n594 925\n186 922\n72 915\n274 174\n144 252\n422 104\n672 652\n624 195\n362 70\n413 347\n27 160\n618 972\n656 346\n874 683\n942 64\n30 952\n569 484\n605 887\n821 321\n661 930\n455 148\n611 342\n572 295\n561 526\n569 103\n458 989\n371 308\n508 41\n603 429\n612 474\n196 349\n778 843\n831 477\n541 939\n99 580\n552 43\n843 385\n863 896\n256 236\n434 160\n602 93\n668 580\n243 925\n267 567\n793 578\n249 452\n116 348\n52 345\n425 397\n398 484\n447 302\n428 208\n222 345\n14 918\n497 491\n715 582\n531 633\n136 497\n307 261\n241 848\n683 100\n433 159\n760 702\n178 197\n605 935\n610 674\n453 583\n644 219\n844 363\n603 950\n645 478\n457 841\n516 156\n304 547\n945 494\n668 670\n277 72\n649 741\n380 366\n812 669\n374 133\n850 937\n525 774\n982 822\n538 186\n9 806\n772 913\n688 565\n879 837\n725 241\n536 741\n935 532\n193 867\n967 5\n610 807\n313 462\n293 64\n951 564\n276 809\n890 395\n450 189\n547 870\n615 651\n387 690\n280 252\n922 916\n691 657\n382 322\n616 629\n274 64\n352 751\n169 599\n551 234\n709 416\n635 309\n0 280\n371 621\n765 869\n602 367\n854 478\n98 16\n901 92\n290 448\n208 860\n620 17\n665 723\n539 512\n2 492\n712 885\n199 260\n408 1\n913 947\n978 27\n240 634\n983 923\n626 53\n29 59\n623 192\n124 325\n808 206\n74 500\n491 490\n744 865\n48 419\n514 376\n124 157\n359 956\n851 364\n928 597\n647 891\n147 622\n78 333\n958 726\n826 266\n807 545\n705 191\n31 281\n625 513\n811 841\n944 158\n702 496\n125 83\n549 375\n911 400\n227 415\n966 660\n866 184\n501 627\n395 713\n777 714\n224 604\n761 722\n851 82\n906 256\n185 682\n535 980\n477 551\n81 149\n344 5\n399 976\n60 965\n911 874\n622 673\n882 630\n456 897\n941 343\n306 34\n245 246\n564 804\n514 67\n630 544\n374 569\n170 0\n416 970\n862 864\n514 945\n479 619\n348 511\n201 444\n731 354\n725 47\n138 520\n263 667\n681 410\n283 389\n405 606\n413 490\n554 365\n89 641\n882 529\n42 740\n110 553\n748 769\n16 819\n688 372\n634 699\n645 74\n619 99\n106 354\n876 785\n510 969\n542 816\n971 432\n649 558\n868 36\n487 21\n940 847\n973 965\n530 464\n362 200\n817 589\n1 190\n258 927\n781 628\n21 217\n378 893\n528 235\n193 363\n758 825\n79 226\n219 620\n756 387\n28 652\n245 635\n29 35", "1032", true, true},
    };
    bool allOK = true;
    int testID = 0;
    std::cout << std::fixed;
    double maxTime = 0.0;
    for(const jhelper::Test& test: tests ) {
        std::cout << "Test #" << ++testID << std::endl;
        std::cout << "Input: \n" << test.input << std::endl;
        if (test.has_output) {
            std::cout << "Expected output: \n" << test.output << std::endl;
        }
        else {
            std::cout << "Expected output: \n" << "N/A" << std::endl;
        }
        if (test.active) {
            std::stringstream in(test.input);
            std::ostringstream out;
            std::clock_t start = std::clock();
            CCC16S3 solver;
            solver.solve(in, out);
            std::clock_t finish = std::clock();
            double currentTime = double(finish - start) / CLOCKS_PER_SEC;
            maxTime = std::max(currentTime, maxTime);
            std::cout << "Actual output: \n" << out.str() << std::endl;
            if (test.has_output) {
                bool result = jhelper::check(test.output, out.str());
                allOK = allOK && result;
                std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
            }
            std::cout << "Time: " << currentTime << std::endl;
        }
        else {
            std::cout << "SKIPPED\n";
        }

        std::cout << std::endl;

    }
    if(allOK) {
        std::cout << "All OK" << std::endl;
    }
    else {
        std::cout << "Some cases failed" << std::endl;
    }
    std::cout << "Maximal time: " << maxTime << "s." << std::endl;
    return 0;
}
