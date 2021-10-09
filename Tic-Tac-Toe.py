from random import randint
from IPython.display import clear_output

# Display board
def display_board(board):
    clear_output()
    print()
    print('\t\t ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('\t\t---|---|---')
    print('\t\t ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('\t\t---|---|---')
    print('\t\t ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print()
    
# Choose the player to go first
def go_first():
    first = randint(1,2)
    if first == 1:
        return 'Player 1'
    else:
        return 'Player 2'

# Prompt ask players to pick their marker
def choose_marker():
    while True:
        marker = input('Pick your mark (X/O): ').upper()
        if marker == 'X':
            return ('X', 'O')
        elif marker == 'O':
            return ('O', 'X')
        else:
            print("INVALID INPUT!!!\nPlease pick again.\n")

# Check if the position is good or not
def good_position(board, position):
    return board[position] == ' '

# Prompt ask players to pick the position
def position_input(board):
    position = 0
    while position not in range(1,10) or not good_position(board, position):
        position = int(input('Choose a number to place your mark (1 - 9): '))
        if position not in range(1,10):
            print('INVALID!!! The input is out of acceptable range (1 - 9)')
        elif not good_position(board, position):
            print('That position has already occupied!!! Choose another place.')
    return position

# Place the marker on the board
def place_marker(board, position, marker):
    board[position] = marker

# The game is tie if the board is full
def full_board(board):
    for n in range(1,10):
        if good_position(board, n):
            return False
    return True

# Win condition of the game
def win_check(board, marker):
    return ((board[1] == board[2] == board[3] == marker) or
            (board[4] == board[5] == board[6] == marker) or
            (board[7] == board[8] == board[9] == marker) or
            (board[1] == board[4] == board[7] == marker) or
            (board[2] == board[5] == board[8] == marker) or
            (board[3] == board[6] == board[9] == marker) or
            (board[1] == board[5] == board[9] == marker) or
            (board[3] == board[5] == board[7] == marker))

# Replay the game
def replay():
    choice = input('Want to play again? Yes (y) or No (n): ').lower()
    return choice == 'yes' or choice == 'y'

# Start the game
def game_start():
    print('\t WELCOME TO TIC-TAC-TOE!!!')
    instruction_board = ['', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    display_board(instruction_board)
    print("--- Use the numbers as instructions to place your marks ---\n")

    while True:
        board = [' '] * 10
        play = input("Ready to play? Yes (y) or No (n): ").lower()
        if play == 'yes' or play == 'y':
            game_start = True
            # Set up players and their markers
            player1_marker, player2_marker = choose_marker()
            player = go_first()
            print(player + ' will go first!')
        else:
            game_start = False

        while game_start:
            if player == 'Player 1':
                display_board(board)
                print(player1_marker + "'s turn")
                # Choose a position
                position = position_input(board)
                # Place the marker on this position
                place_marker(board, position, player1_marker)
                
                if win_check(board, player1_marker):
                    display_board(board)
                    print('Player 1 is the winner!')
                    game_start = False
                elif full_board(board):
                    display_board(board)
                    print('Good game! It is a tie')
                    game_start = False
                else:
                    player = 'Player 2'

            else:
                display_board(board)
                print(player2_marker + "'s turn")
                # Choose a position
                position = position_input(board)
                # Place the marker on this position
                place_marker(board, position, player2_marker)
                
                if win_check(board, player2_marker):
                    display_board(board)
                    print('Player 2 is the winner!')
                    game_start = False
                elif full_board(board):
                    display_board(board)
                    print('Good game! It is a tie')
                    game_start = False
                else:
                    player = 'Player 1'
    
        if not replay():
            break

game_start()
       
if __name__ == "__main__":
    pass