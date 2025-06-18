#include <stdio.h>
#include <stdlib.h>
#include"../inc/stoppedState.h"
#include"../inc/playingState.h"
#include"../inc/musicPlayer.h"
#include"../inc/playerState.h"

static void pressPlay(PlayerState *state) {
    printf("Starting music...\n");
    // Change to PlayingState
    state->player->changeState(state->player, playingStateCreate());
}
static void pressPause(PlayerState *state) {
    printf("Cannot pause. Music is already stopped.\n");
}
static void pressStop(PlayerState *state) {
    printf("Music is already stopped.\n");
}
static void setContext(PlayerState *state, struct MusicPlayer *player) {
    state->player = player;
}

PlayerState* stoppedStateCreate() {
    PlayerState *state = (PlayerState*)malloc(sizeof(PlayerState));
    state->pressPlay = pressPlay;
    state->pressPause = pressPause;
    state->pressStop = pressStop;
    state->setContext = setContext;
    state->player = NULL;
    return state;
}