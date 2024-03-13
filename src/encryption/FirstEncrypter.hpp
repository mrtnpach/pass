#pragma once
#include <random>

class FirstEncrypter
{
    public: 

    FirstEncrypter();
    ~FirstEncrypter();

    int GenerateRandomNumber();
    int GenerateSeed(const char* name);
    std::string GeneratePassword(const char* inputString, const int userSeed, const int siteSeed, const size_t length);

    private:

    size_t CalculateStringLength(const char* string);

    // TWEAKS: Digits bank
    const char digitsBank[20][50] = 
    {
        "zYcf*};6;P-[f3,)}p[zZhD/}aD,7NK{gJmSCQ8L}PMXQTwCF",
        "]Ek&,Gt97nYV#n}Sm]X-]Kxbg8KtFbYxw,e9Nhtg[{w[!UM87",
        "ACwCV=S;8HSAY:LaYt3#9izJj]5W.ehY+[!fMK4j*@%tr#ev*",
        "2]#L79tjmzrwyLqv[3#$B{[)P_?mqSwXWy9m2BCAwz4]MUgd{",
        "vn_2vi&_zJe8c!/W5.APx?-K6n$]ZJ96bb/;rUk?:,$h6}b;Q",
        "iyCu]VSPQgGBX3KZiMm2L3&acvvt@p{_&Trc3jF_,6AJr,_/:",
        "Z3tmg(2]LPNW{n-8h48nHN6!y/Bc)T[tU$uezW/wEw[$*ihLL",
        "n=rWgeFXKpZ5ygD@=Q(FL;DZx[GU@.}jzYmrT9?LduY[#UvUh",
        "Df7)j,jHB-i3n3[@HG+rd!3aizftQ)Kb2$Hvr563wx5.Nyj5b",
        "Z=!X!-H?DfHS=yeFC#j)$$Mc,yn5N{wzAJKvd_$8zRP2jX*}$",
        "VqE4jXUFvzR&nC;4-4C#zwUNfGx_XAR*N&bYtz?;ECkuf?jG%",
        "S#/d4_cwr2@c:QuREC5R7i.AhKTaSF#(NjP@*u4a7NxS+/!qL",
        "7?A3zDt,2GCDtg:WBD&LkKt2F:hgY]:355B;WW*vhf/{%h9ML",
        ".GnF]MC{Yk.PFKphp%t&gJ&kacStDc;j(6pM@!M9m(&FU-BcZ",
        "ug*wArieW@hyw=$CCb=JwbQywXKbFZ==Y2jtT7bKY&QQ+L8Qc",
        "::n2b//:-S}Ai2=(XK#Yk)V)8$ic43q_Y;htG/$q7Gdbmv7%q",
        "(f$j8giU!2_TQ6a)aRr]A%{LG_meQg.(@K(/2tq[6/+r+Lv6D",
        "kn[e8qX.!F@{(Lv3q:wB3yxpMMn}[/T-7B.?{Kx36S3.-+;6h",
        "8g}$;yPn(F3;/gd-;9qu!b]ewTEt6gK_G6QY,Y(bxMafm=9.!",
        "w(etfm@}-:Rej%-kk@tr*:f45,i3j@ryCcV*A!gY:pd?y3C_="
    };

    int _digitBankRowCount;
    int _digitBankColumnCount;

    // TWEAKS: Other values
    // Values for FirstEncrypter::GenerateSeed
    int _customSeed = 4912;
    // Values for FirstEncrypter::GeneratePassword
    int _saltConstant = 277;
    int _rowSelectionSalt = 5271;
    int _columnSelectionSalt = 9658;
};