# -*- coding: utf-8 -*-
import random

# variable de programe

quit = False
score = 0
best_score = 0
run = True
reponse = 0


# fonction qui pose la question

def question():
    global reponse

    # poser la question

    essai = input('entrez un nombre entre 0 et 1000: ')

    # boucle qui pose la question si repones nes pas un chiffre valide

    while not essai.isdigit():
        essai = input('un chiffre valide: ')

    # transformer la reponse en chiffre valide

    reponse = int(essai)


# boucle principale

while quit  False:

    # varialbe de la boucle

    chiffre = random.randint(0, 1000)
    repete = 0

    # loader le best_score du fichier

    with open('best.txt', 'r') as reader:
        best_score = int(reader.read())
        print best_score

    # boucle de jeu

    while run:

        # variable de boucle

        chiffre = random.randint(0, 1000)
        repete = 0
        question()

        # boucle qui permet d avoir 10 essai

        while repete <= 10:
            print repete

            # verification pour voir qui a gagne

            if reponse == chiffre:
                print 'bravo tu a gagne un point'
                score += 10 - repete
                print score
                break
            else:

            # mauvaise reponse
                # si le nombre choisi est plus petit

                if reponse < chiffre:
                    print 'choississez un nombre plus grand'

                # si le nombre choisi est plus grand

                if reponse > chiffre:
                    print 'choississez un nombre plus petit'

            question()
            repete += 1

    if score == best_score:
        best_score = score

    # enregistre le best_score

    with open('best.txt', 'w') as writer:
        writer.write(best_score)

    # recommencer la partie

    reponse = input('voulez vous rejouer (oui ou non):')
    if reponse == 'non':
        quit == True
