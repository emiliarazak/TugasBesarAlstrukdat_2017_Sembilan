#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "player.h"
#include "listunit.h"

void initialkata();
/* Menginisialisasi kata yang termasuk dalam command2 pemain */

void StartGame();
/* Memulai game, di mana semua state awal dibuat */

void openingturn ();
/* Menginisialisasi state awal dari giliran pemain */

void execute();
/* Mengeksekusi perintah yang di-inputkan pemain */

void readcommand();
/* Membaca command yang diinputkan pemain */ 
/* Command yang diinputkan pemain melalui keyboard akan dikirim dulu ke
   file eksternal, kemudian dibaca menggunakan ADT mesin kata  */

void AttackAndRetaliate(Player *P1, Player *P2);
/* Mengeksekusi command attack yang dilakukan pemain sekaligus mengeksekusi
   atau meng-update atribut pemain bila enemy melakukan retaliate */

void PrintListEnemy (ListU L, int *choice);
/* Mencetak daftar semua enemy yang adjacent dengan player */

void HealPlayer(Player *P);
/* Melakukan heal pada unit yang adjacent dengan white mage nya */

int winningcheck();
/* Mengecheck apakah permainan berakhir, 
   kalah-menang, atau dilakukan command exit */

#endif
