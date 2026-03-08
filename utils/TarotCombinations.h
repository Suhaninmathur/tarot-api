#ifndef TAROT_COMBINATIONS_H
#define TAROT_COMBINATIONS_H

#include <string>
#include <map>
#include <tuple>
#include "../models/User.h"    // User::Mood enum
#include "../models/TarotCard.h"      // TarotReading struct (single definition)

// Card enum — 1-indexed to match User::Mood numbering convention
enum CardId {
    TheFool = 1, TheMagician, TheHighPriestess, TheEmpress,
    TheEmperor, TheLovers, TheChariot, Strength, TheHermit, TheStar
};

using TarotKey = std::tuple<CardId,CardId,CardId>; // Past, Present, Future
using TarotMap = std::map<TarotKey, TarotReading>;

// Mood-aware text decorator — uses User::Mood so it matches User.h
inline std::string applyMoodTone(const std::string& text, User::Mood mood) {
    switch(mood) {
        case User::Mood::Happy:    return "The cards are bright today — " + text;
        case User::Mood::Sad:      return "I hear the weight you are carrying — " + text;
        case User::Mood::Neutral:  return text;
        case User::Mood::Confused: return "The cards often speak to confusion — " + text;
        case User::Mood::Excited:  return "Your energy is electric right now — " + text;
    }
    return text;
}

// All 720 ordered card combinations — written in authentic tarot reader voice
inline TarotMap generateTarotMap() {
    TarotMap map;

    map[{TheFool, TheMagician, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "You leapt, and in leaping you discovered your own hands — what they can hold, what they can build. Now the cards are asking you to stop and listen beneath all that doing. The next great move will come from the quiet, not the noise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, TheMagician, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "You began with nothing but nerve, and along the way you found your gifts. Now the universe is ready to reward that combination of courage and craft with genuine abundance. Something is ripening. Do not pick it too early.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, TheMagician, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The free spirit found its power, and now power is asking to be given a form that lasts. You have the energy and the skill — build the structure that will hold it. Discipline is not a cage. It is how wild things survive winter.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, TheMagician, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "You took the leap, you found your power, and now you stand at a crossroads of the heart. Everything you have built and everything you have the skill to create comes down to this: what do you actually choose? Choose it fully.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, TheMagician, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "From innocence to capability to unstoppable momentum — this is a warrior's arc. You are not the person who fell off that cliff anymore. You are someone who knows how to fly. Now aim and move.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, TheMagician, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "You found your tools, you learned your craft, and now the work asks something deeper of you — not more cleverness, but more patience. Real mastery is never rushed. Hold the lion gently.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheMagician, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After all the creating and beginning, the lantern is calling you inward. What you have built is real. Now ask the deeper question: what was it all for? The Hermit will help you find the answer.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheFool, TheMagician, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "From the edge of the cliff to the master's table to the open sky of hope — this is a luminous arc. Every step of this journey has been building toward something genuinely beautiful. Let yourself believe in it.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, TheHighPriestess, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "You leapt and landed in mystery — and now from that deep inner knowing, real creative power is emerging. What your intuition has been telling you is true. Act on it. The Magician is waiting for the High Priestess to give him direction.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, TheHighPriestess, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Innocence opened the gate to inner knowing, and now that knowing is flowering into abundant life. Trust what you feel. The growth coming toward you is not accidental — it is the direct harvest of listening to yourself.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, TheHighPriestess, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From a wild beginning through the inner world, structure now calls. The order you need to build should not be borrowed from someone else's blueprint — it should come from what you already know is true about yourself.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, TheHighPriestess, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "You began open, then grew wise, and now you face a choice that only wisdom can navigate. Do not let the mind decide this alone. Your intuition has been right about you before. Let it weigh in on this.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, TheHighPriestess, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner knowing gained through a courageous beginning now fuels forward movement. You are not moving blindly anymore — you are moving with the inner compass of someone who has done the work. Trust it.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, TheHighPriestess, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The quiet wisdom you earned through innocence and inner work is about to be tested. Whatever comes, you have a resource most people overlook: you actually know yourself. That is your greatest strength.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheHighPriestess, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "Two energies of deep inner searching are moving through you. This is not a time to be distracted by the surface of things. The truth you are looking for is within — and it has been waiting for you to sit still long enough to hear it.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheFool, TheHighPriestess, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "You began with an open heart, found your inner wisdom, and now hope arrives like a clear sky after rain. Everything you went through inwardly was preparing you for this moment of genuine renewal. Receive it.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, TheEmpress, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "What you nurtured and grew is now ready to be shaped with real skill. The fertile season is not over — but it is shifting. Take what has blossomed and bring it deliberately into form. Creation is calling.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, TheEmpress, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "Growth and abundance have been real gifts in your life, and now the cards ask you to go beneath them. What is the quiet truth growing underneath all that richness? Listen for it. She knows things the surface does not.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, TheEmpress, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From free spirit to flourishing creator, now the time of structure arrives. What has grown needs tending — and tending requires boundaries, commitment, and yes, some discipline. This is not the end of abundance. It is how you protect it.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, TheEmpress, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "You grew, you bloomed, and now love — or a deep values-choice — stands before you. What you have cultivated in yourself is ready to be offered to something or someone else. Give it consciously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, TheEmpress, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "The season of growth has given you real fuel. Now take it somewhere. The Chariot is not asking you to leave the garden — it is asking you to carry its abundance with you as you move forward with purpose.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, TheEmpress, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Abundance has been your reality, and now a test of patience and inner courage approaches. The strength you need is not hard or aggressive — it is the deep, warm, steady kind. The kind that tends things even when it is difficult.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheEmpress, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After a rich season of growth, solitude is calling. This is not a loss — it is a natural harvest. Go inward and sit with what you have created. Understanding what it all means is as important as the growing itself.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheFool, TheEmpress, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "From a free beginning to a flowering life to a radiant future — I want to say this plainly: you are going to be okay. More than okay. The hope ahead of you is well-founded. You have earned it.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, TheEmperor, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "You found your authority, your sense of structure and order, and now from that grounded place — real creation is possible. Build something worthy of the foundation you have laid. You have both the discipline and the skill.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, TheEmperor, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "After establishing outer order, the inner world calls. You have built your structures well. Now: what do they mean? Sit with the High Priestess. She will show you what the Emperor cannot.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, TheEmperor, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Order has been established, and now the feminine, creative, abundant force wants to move through it. Let it. The best structures are not walls — they are trellises. Let the vine grow.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, TheEmperor, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "From free spirit to builder of order, now the heart stands before you asking to be honoured. Build your relationships with the same integrity you bring to everything else. Love deserves your best architecture.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, TheEmperor, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Discipline earned through experience now launches decisive, focused forward momentum. Every hard thing you built — every boundary, every structure — has been preparing you for this charge. Now move.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, TheEmperor, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The authority you built is real. And now it meets its most important test: can you govern yourself as well as you govern your outer world? Inner mastery is the final frontier. Walk toward it.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheEmperor, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The ruler steps back from the throne to search for wisdom. This is not weakness — it is the most courageous thing a person in power can do. What you find in solitude will make you a better builder when you return.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheFool, TheEmperor, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "From wild freedom to disciplined order to radiant hope — this is the arc of a life genuinely lived. What you have built with intention and honesty will stand. And it will be beautiful. The Star confirms it.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, TheLovers, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "A real choice was made — from the soul, not from convenience — and that choice unleashed a creative power you could not have accessed otherwise. The most authentic decisions open the most authentic possibilities.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, TheLovers, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "You chose with your heart, and now your inner knowing deepens around that choice. Something the mind could not have told you is becoming clear. Sit with it. The High Priestess is showing you what you actually chose.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, TheLovers, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "A genuine choice made from the heart leads to genuine flourishing. This is not a coincidence. Authentic alignment with your values is the most fertile ground of all. Watch what grows.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, TheLovers, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The choice of the heart now calls for the structure of the mind. Love without commitment is just feeling. Give what you have chosen the architecture of real intention — and it will last.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, TheLovers, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "You chose your direction with your whole heart, and now nothing is holding you back. The Chariot after the Lovers is a sign that when you move from your deepest truth, the path actually opens. Drive.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, TheLovers, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The most courageous thing you have done is to choose openly — and now courage in a different form is being asked. The patient, quiet kind. The kind that shows up even when it is not easy. That is real love.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheLovers, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After the choice, solitude. This is right and necessary. Go be alone with what you have committed to. Understand it. Love it quietly. The Hermit teaches you to stop performing your choices and start living them.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheFool, TheLovers, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "A courageous choice led to hope. That is what this spread is telling you. You chose with your heart, and the universe noticed. What is coming is a genuine renewal — partly because you were honest enough to choose it.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, TheChariot, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "You drove hard and you moved fast, and now from all that motion — the moment to create deliberately has arrived. You have proven you can move. Now prove you can build. The Magician is ready when you are.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, TheChariot, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "After all that speed and determination, the silence is calling. Not every battle is won by charging forward — some victories are won in the stillness between actions. Slow down. What has not been heard needs to be heard now.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, TheChariot, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The victory of the Chariot is settling into the warmth of the Empress, and that is exactly right. You fought, you won, and now abundance awaits. Receive it. Let the warrior rest and the nurturer take over for a season.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, TheChariot, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From determined momentum to lasting structure — you are building an empire from motion. Every ounce of willpower you spent in the past is now crystallising into something permanent. Keep going. You are close.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, TheChariot, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The chariot stops at the crossroads. After all the forward momentum, a real choice now stands before you. Do not let speed carry you past it. This decision requires your full presence. Stop. Look. Choose.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, TheChariot, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Speed and will have been your allies, but the road ahead requires something else — patience, compassion, and the quiet kind of power. The race is not ending; it is becoming something deeper. That is a promotion, not a defeat.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheChariot, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The race is run. Now the Hermit invites you to sit with what you have accomplished — and what it cost you. Not all victories look the same up close. Solitude will give you an honest account.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheFool, TheChariot, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "From a fearless beginning to relentless drive to a shining future — this is the arc of someone who refused to stop. And the Star is telling you: the destination is worth it. Keep your eyes on that light ahead.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, Strength, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "You have already faced your fear — already looked the lion in the eye — and now from that quiet place of inner victory, conscious creation is yours. The most powerful magic comes from those who have already proven they cannot be broken.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, Strength, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "Inner courage has led you to the threshold of inner mystery. Those who have genuinely mastered themselves earn access to deeper layers of knowing. The High Priestess does not open to the frightened — only to the brave.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, Strength, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Quiet inner power opens into abundant outer flourishing. This makes complete sense — when you are at peace with yourself, you stop blocking the flow of good things. Receive the abundance coming your way.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, Strength, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From playful innocence to inner mastery to outer authority — you are becoming a leader worth following. The Emperor you are stepping into has done the inner work. That is rare. That is real.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, Strength, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Only those who have faced their own shadows can truly offer themselves to another. The courage you have cultivated is the very thing that makes you capable of genuine, honest, enduring love. Choose with all of it.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, Strength, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner mastery now fires the engine of unstoppable forward motion. This is the combination that builds legacies — not force, but quiet, steady, directed power. You have already won the hardest fight. Now drive.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, Strength, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After mastering the inner lion, solitude gives that victory room to breathe. The Hermit arrives not as loneliness but as depth. Take your hard-won courage into the quiet and see what it becomes.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheFool, Strength, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "You began open, you stayed courageous, and now hope arrives in full. Every inner battle you have fought and won with grace has been building the light that the Star is now confirming. You earned this.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, TheHermit, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Solitary wisdom, earned in the quiet, now rises to meet the moment of creation. What you found in your aloneness was not emptiness — it was fuel. The Magician is ready to take everything the Hermit discovered and make it real.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, TheHermit, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "Two great inward journeys converge, and the depth here is rare. You are moving into a relationship with your inner life that few people develop. What you learn there — no one can take from you.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, TheHermit, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "From the cave to the garden — the wisdom planted in solitude is about to bloom abundantly. Do not rush the transition. But know that what you tended in your quiet period is about to show itself in the most beautiful way.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, TheHermit, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Wisdom earned through solitude now calls for outer authority and structure. Go build, knowing that what you build is founded not on ambition alone but on genuine self-understanding. That is rare and powerful.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, TheHermit, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Time alone has prepared you for a genuine choice about love and values. You know yourself now — and that means you can choose clearly, without the noise of other people's opinions. Choose from your own quiet truth.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, TheHermit, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "The lantern has shown you the path; now the Chariot asks you to drive it. Inner clarity is a gift — but it must be put into motion to matter. You know where you are going. Now go.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, TheHermit, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Solitude revealed the source of your truest courage. What you found in the quiet — that is your strength. Not borrowed, not performed. Completely your own. Carry it forward.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheHermit, TheStar}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Fool moving into Hermit and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheFool, TheStar, TheMagician}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Fool gave you the foundation; Star is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheFool, TheStar, TheHighPriestess}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Fool's energy in your foundation, Star's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheFool, TheStar, TheEmpress}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Fool's energy in your foundation, Star's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheFool, TheStar, TheEmperor}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Fool gave you the foundation; Star is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheFool, TheStar, TheLovers}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Fool's energy in your foundation, Star's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheFool, TheStar, TheChariot}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Fool moving into Star and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheFool, TheStar, Strength}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Fool, Star, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheFool, TheStar, TheHermit}] = {
        "I see the Fool sitting in your past — there was a moment, perhaps not so long ago, when you threw caution to the wind. You stepped off a ledge, maybe without a plan, maybe without permission. That leap shaped everything that followed.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Fool moving into Star and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, TheFool, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "From mastery into a fresh beginning, and now the inner voice calls. You have proven you can do — now discover what you know. The High Priestess is teaching you that the deepest skill is listening.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, TheFool, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "After mastery, a new beginning opens into abundance. Every skill you developed prepared this fertile ground. Begin again from a place of real richness — you are not starting from zero. You are starting from everything.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, TheFool, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From skilled creation to a bold new beginning, now structure asks to anchor what you have started. You have the raw energy of a new chapter and the wisdom of experience behind you. Build something that lasts.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, TheFool, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Your mastery and fresh start have led you to a crossroads of the heart. What you choose now will define this next chapter. Choose with the same intentionality you brought to your craft.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, TheFool, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Skill, new beginnings, and unstoppable momentum — this is a combination that moves mountains. You have the craft and the courage. Now harness them both and drive without hesitation.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, TheFool, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "After mastery and new beginnings, the deeper work of inner resilience calls. Brilliance alone does not sustain a life — patience and quiet courage do. This is the next skill to develop.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheFool, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "From creating to beginning again to searching within — this is the cycle of genuine wisdom. You have made things, started things, and now the invitation is to understand them more deeply in stillness.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, TheFool, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Skill, a fresh start, and a luminous future ahead. This is not accidental. Every deliberate act of creation, every courageous new beginning, has been pointing toward this open horizon. Step into it.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, TheHighPriestess, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The hand and the heart have been working together, and now a completely new beginning beckons. You are not starting without resources — you are starting with both skill and wisdom. That is a rare and powerful combination.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, TheHighPriestess, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Intention guided by intuition naturally flowers into abundance. This is the most aligned creative path there is — acting from both what you can do and what you know to be true. What is blooming is no accident.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, TheHighPriestess, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Will and inner wisdom now call for organised, lasting structure. The Emperor after the High Priestess says: do not just know what is right — build a life that reflects it. Put your wisdom into architecture.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, TheHighPriestess, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Power and inner knowing converge at the altar of a meaningful choice. You have all the information you need — the skill, the intuition, the desire. Now honour them all and choose with your whole being.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, TheHighPriestess, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Intent guided by genuine inner knowing produces the most effective, purposeful action of all. You are not just moving fast — you are moving right. Trust the direction and drive.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, TheHighPriestess, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Conscious creation balanced with deep intuition leads to a strength that is unusual — it is both capable and compassionate. The lion meets the Magician, and neither flinches. That is the kind of power that endures.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheHighPriestess, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After skillful action and inner listening, the Hermit offers the deepest gift: integration. In the quiet, what you have made and what you know will come together into wisdom you cannot get any other way.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, TheHighPriestess, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Skill and intuition together are a visionary combination, and the Star confirms it — this path leads somewhere genuinely luminous. Keep trusting both your hands and your inner knowing. They are taking you somewhere real.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, TheEmpress, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Creation and abundance have ripened you for a bold new beginning. You are not naive anymore — you are rich with experience and ready. The next chapter begins from a place of genuine fullness.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, TheEmpress, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "From skilled creation to abundant growth, now inner wisdom deepens everything. Sit with what you have built and what has flourished. Beneath the surface of it all, the High Priestess has something to show you.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, TheEmpress, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "What has grown wild and richly must now be given form and tended with intention. The Emperor arrives not to stop the abundance but to protect it. Give your flourishing life the structure it deserves.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, TheEmpress, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Skillful creation led to real abundance, and now love — or a choice that engages your whole heart — stands before you. Share what you have built. The most meaningful connections grow from genuine generosity.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, TheEmpress, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Rich, nurtured abundance now fuels a forward charge. You are not moving from lack — you are moving from fullness. That changes everything about the quality of your momentum. Drive with that truth behind you.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, TheEmpress, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Creation and abundance have built something worth tending with care. Now quiet, patient inner strength is called for. Tend what you have made with the same devotion that grew it. Do not rush what needs time.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheEmpress, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After building and flourishing, the Hermit calls you into the deep quiet of appreciation. What have you really made? What does it mean? Go inward with those questions. The answers are richer than you expect.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, TheEmpress, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "From manifestation to abundance to a radiant future — this is one of the most beautiful arcs in the deck. Everything you have built with intention and tended with care is moving toward a genuinely hopeful horizon.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, TheEmperor, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "After building systems and structures, something in you is ready to start fresh. And you can — because you have the wisdom of a builder now. Begin again not from naivety, but from real, earned freedom.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, TheEmperor, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "You have built an impressive outer life, and now the inner world is asking for equal attention. The High Priestess calls to the Magician-Emperor: go within. What authority cannot tell you, stillness can.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, TheEmperor, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Structure and discipline create the conditions for genuine flourishing. The Emperor has laid the groundwork, and now the Empress can fill it with life. Let warmth and creativity move through what you have built.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, TheEmperor, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Power and structure have been established — now the heart asks to be honoured with equal integrity. Build your most important relationships with the same care and honesty you bring to your work.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, TheEmperor, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Skill, structure, and focused momentum — you are fully equipped and fully prepared. This is a charge that can win. Move with the confidence of someone who has done every bit of the preparation.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, TheEmperor, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "After building outer power, the territory of inner mastery opens. You can govern a room — can you govern yourself with the same steady hand? That is what the future is asking. The answer will surprise you.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheEmperor, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The person who built great things now steps back to ask why. This is wisdom, not weakness. The Hermit after the Emperor tells me you are ready to lead from depth rather than from position.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, TheEmperor, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Skill, structure, and the open sky of hope — this spread describes a life built with genuine intention, now arriving at its reward. What you have made will stand. And it will carry the light of the Star.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, TheLovers, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "A meaningful, authentic choice has freed you into a bold new beginning. You are lighter because you chose honestly. Begin this new chapter knowing that the next choice will be just as important as the last.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, TheLovers, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "Will and love have brought you to the doorway of deep inner knowing. Go quiet with this. The most important truths about your relationships — and yourself — are not found in analysis but in listening.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, TheLovers, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "A skillful heart chose love, and love responded with abundance. Authentic connection is the most generative creative act of all. What is flourishing in your life now grew from a seed of genuine choice.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, TheLovers, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Meaningful choice now calls for real structure and commitment. Love without architecture drifts. Give what you have chosen the framework of honesty, boundaries, and real intention. Then watch it stand.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, TheLovers, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When head and heart are aligned, the path forward is unstoppable. You have done the work of choosing, and now the Chariot says: move. There is nothing to second-guess. Everything is pointing the same direction.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, TheLovers, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "A conscious, loving choice now calls for patient, resilient devotion. The grand romantic gesture is the beginning, not the end. Real love is what you do on the ordinary days. That is the Strength card.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheLovers, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After choosing and creating, solitude offers the gift of real understanding. Go be alone with what your deepest relationships are showing you about yourself. The Hermit does not separate you from love — he deepens it.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, TheLovers, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Skill and love united — and the Star confirms this is moving toward something genuinely healing and hopeful. The partnerships you have built from your whole self are a light in the world. Trust them.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, TheChariot, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "After driving hard and proving your power, something new and fresh calls. Step into the new chapter with all the confidence of someone who has already won — because you have.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, TheChariot, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "After skill and driven momentum, stillness. This is not failure — it is the necessary turn inward that all great movement eventually requires. Not every answer comes from going faster. Some come from going deeper.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, TheChariot, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Determination and focused drive have earned a season of real flourishing. Rest in the abundance your effort created. The Empress is not asking you to stop — she is asking you to enjoy what you have won.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, TheChariot, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Skill and momentum now want to become lasting structure. The fire of forward motion is ready to be channelled into something permanent. Build now. The foundation will be strong because the energy behind it is real.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, TheChariot, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "You have been moving powerfully and now the crossroads stands before you. Slow down enough to honour this decision. Not everything that momentum carries you toward is where you should actually go.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, TheChariot, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "You have moved fast and far, and now the deeper terrain of patient inner power opens up. The long road is different from the sprint. Let strength, not speed, become your primary currency now.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheChariot, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After all the skillful motion, rest and reflection are not optional — they are the next essential step. The Hermit after the Chariot says: the journey has given you something. Go find out what it is.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, TheChariot, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Skill, momentum, and a luminous horizon — this is the spread of someone who has been moving in the right direction. The Star is not a coincidence here. Keep going. It is real.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, Strength, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Inner power consciously cultivated now opens a new, unburdened beginning. You have already done the hardest work. Now step into what is next knowing that you cannot be truly broken. That changes everything.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, Strength, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "Conscious creation and inner resilience now open into intuitive depth. The deepest knowing belongs to those who have both acted and endured. You have done both. Now listen.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, Strength, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Skill and inner power together create the ground for real, lasting abundance. What is built with both craft and courage grows in every dimension — outward and inward simultaneously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, Strength, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Manifestation and inner mastery now call for grounded, lasting authority. The Emperor you are becoming has done the work — inside and out. Lead from that complete place.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, Strength, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Creation and inner courage have brought you to the moment of genuine, wholehearted commitment. Say yes from your full self — not from one part, not from fear or obligation. From your whole truth.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, Strength, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner mastery fires the engine of truly focused, directed movement. When you are at peace within yourself, nothing external can genuinely stop you. That is not confidence — that is fact.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, Strength, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After skillful action and quiet inner courage, solitary wisdom calls. Take your strength into the quiet and see what it reveals about the meaning of everything you have built and endured.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheMagician, Strength, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Mastery and resilience have built a soul that is genuinely ready for hope. The light ahead is real, and you have the inner resources to walk all the way toward it. Keep going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, TheHermit, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Inner wisdom gathered in the quiet now calls for a bold, fresh beginning. Step out carrying your lantern and your craft. Begin again — not in ignorance, but in genuine, self-possessed freedom.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, TheHermit, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "Skillful creation and solitary reflection open the deepest doors of inner knowing. Trust the quiet completely. It is speaking a language that your mind alone cannot fully decode.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, TheHermit, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Wisdom born in solitude is about to flower into abundant life. What was understood in the quiet is ready to be expressed in the open. The transition from cave to garden is a beautiful one. Move through it.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, TheHermit, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From inner wisdom to organised, grounded leadership — this is the arc of someone who builds from depth. The Emperor you are becoming leads not from ego but from genuine understanding. That is rare.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, TheHermit, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Self-knowledge earned in solitude prepares you for the most honest, wholehearted choice you can make. You cannot truly choose for another until you truly know yourself. Now you do. Choose.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, TheHermit, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Magician, Hermit, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, TheHermit, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Solitary reflection has revealed the source of your deepest, most sustainable courage. What the Hermit showed you about yourself — that is your real strength. Not performance. Not force. Just truth.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheHermit, TheStar}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Magician, Hermit, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheMagician, TheStar, TheFool}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Magician, Star, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheMagician, TheStar, TheHighPriestess}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Magician gave you the foundation; Star is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheMagician, TheStar, TheEmpress}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Magician, Star, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheMagician, TheStar, TheEmperor}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Magician, Star, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheMagician, TheStar, TheLovers}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Magician's energy in your foundation, Star's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheMagician, TheStar, TheChariot}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Magician's energy in your foundation, Star's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheMagician, TheStar, Strength}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Magician's energy in your foundation, Star's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheMagician, TheStar, TheHermit}] = {
        "The Magician sits at the root of your story. You have been here before — standing at the table with every tool laid out before you, feeling that electric sense that you could make something from nothing. That power is in your bones.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "These three cards together — Magician, Star, and Hermit — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, TheFool, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Inner wisdom sparked a brave new beginning, and now that beginning is empowering real, conscious creation. Trust what your intuition ignited — the Magician confirms it was pointing toward something real.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, TheFool, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Mystery and a fresh start now give way to rich, creative flourishing. The seeds of inner knowing are bearing beautiful, tangible fruit. Let the abundance come without apology.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, TheFool, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From inner knowing to bold beginnings, structure now calls. The order you are building should reflect what you genuinely know to be true — not borrowed rules, but your own hard-won understanding.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, TheFool, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Wisdom, new beginnings, and now a profound choice. Do not let the freshness of the new chapter rush you into a decision. Your intuition has been right before. Let it weigh in here too.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, TheFool, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner knowing and fresh courage now power focused, purposeful movement. You are not moving blindly — you are moving guided by a compass most people do not even know they have. Trust it.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, TheFool, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Intuition and new beginnings have built a quiet, unshakeable inner power in you. What is coming will test it — and you will meet the test with a grace that surprises even you.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheFool, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The High Priestess led to the Fool, and now the Hermit calls inward again. This is not a circle — it is a spiral. Each time you go within, you go deeper. There is more to discover than last time.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, TheFool, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Inner wisdom, a new beginning, and now radiant hope. Everything you went through inwardly was preparing you for this moment. Receive the renewal that is coming. It is well-deserved.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, TheMagician, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Intuition and skill have set the stage for a bold new chapter. Begin again carrying both the wisdom of the inner world and the proven tools of the outer one. That is a powerful combination to start with.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, TheMagician, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Intuition channelled through skill now creates abundant, flourishing growth. When the inner and outer work together — when your instinct and your craft align — nothing is held back. What is growing is real.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, TheMagician, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Inner wisdom and active skill call for structured, lasting authority. Build your systems on the foundation of what you genuinely know to be true. That is the kind of authority that does not crumble.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, TheMagician, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Intuition and skillful action bring you to a crossroads of the heart. The right choice here is the one that aligns your inner truth with your outer life. You know which one that is.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, TheMagician, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner wisdom and deliberate skill power a truly purposeful forward charge. You know where you are going and you have what it takes. Now let yourself move without second-guessing.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, TheMagician, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Intuition and manifestation power now deepen into patient, quiet resilience. The greatest magic is always enacted over time. Tend the work with steady hands and an open heart.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheMagician, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "Inner wisdom and skilled creation call you now into deeper solitary reflection. The Hermit is waiting with a lantern that can show you the meaning behind everything you have built and learned.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, TheMagician, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Balanced action with intuition creates visionary, luminous outcomes. The Star confirms you are on the right path — both the doing and the knowing have been guiding you here.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, TheEmpress, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "From rich inner knowing to abundant creativity, a fresh beginning calls. What has been nurtured in the depths is ready to burst into the open world. Step out. It is time.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, TheEmpress, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Intuition and abundance now fuel conscious, skillful creation. You have everything you need — inner wisdom, outer richness, and the will to act. The Magician is asking: what are you waiting for?",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, TheEmpress, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Inner wisdom and creative abundance now call for organised structure. Give form to what has grown freely, and it will last far longer. The structure protects the abundance — it does not replace it.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, TheEmpress, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "From mystery to abundance, the heart now faces a defining choice. What you have nurtured in yourself is ready to be offered in genuine relationship. Give it consciously — and completely.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, TheEmpress, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Intuitive richness and creative flourishing now propel focused, joyful forward motion. You are both guided and gifted. Move with the confidence that comes from knowing you have both.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, TheEmpress, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Inner wisdom and abundant creativity have built a reservoir of quiet power. Draw on it freely. It is deeper than you know, and it will not run dry — especially not for someone who has tended it as you have.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheEmpress, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "From inner mystery to outer abundance, solitude now offers integration. Go within to understand the full depth of what you have grown. Some things can only be appreciated in the quiet.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, TheEmpress, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Intuition and abundance converge in a future of luminous, expansive hope. You are living proof that inner wisdom, lovingly tended, flowers beautifully. The Star is simply agreeing.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, TheEmperor, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Wisdom and authority have earned you the right to a genuinely new beginning. Step forward with both the insight of someone who has seen deeply and the openness of someone who is not done learning.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, TheEmperor, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Inner knowing and structured authority now empower deliberate, skillful creation. Lead and create from a place where both your wisdom and your power are fully engaged. That is rare capacity.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, TheEmperor, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Intuition and authority together now invite abundant, flourishing growth. Balance logic with nurturing and structure with warmth. The Emperor and Empress working together are unstoppable.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, TheEmperor, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Wisdom and structure now demand honest, values-aligned choice in relationship. Build love the same way you build everything else — with integrity, with intention, and with your whole self.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, TheEmperor, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner knowing and disciplined authority now unleash focused, triumphant momentum. You are fully prepared. Now drive, and trust that every bit of structure you built is the foundation beneath your speed.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, TheEmperor, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Wisdom and outer authority now turn toward the conquest of inner terrain. True power governs within as firmly as it governs without. That is the frontier. Walk toward it.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheEmperor, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "From inner wisdom to outer authority to solitary reflection — the wisest cycle of all. The most courageous thing a person with power can do is lay it down and search for something deeper. You are ready for that.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, TheEmperor, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Intuition and authority together build a future of enduring, inspired hope. What is built on wisdom and honest structure will last and will shine. The Star is simply the confirmation you did not need but deserve.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, TheLovers, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Wisdom and a deep choice have freed you into a bold new beginning. Start this next chapter lighter, having chosen with your whole self. You did the hard thing. Now begin the beautiful thing.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, TheLovers, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Inner wisdom and a meaningful choice now empower skillful, intentional creation. The decisions made from the heart become the fuel for the most powerful and authentic action.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, TheLovers, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Intuition and love now flower into abundant, creative richness. What you have chosen from your truest self is already beginning to bloom. This is not luck — this is alignment.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, TheLovers, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Wisdom and love now require clear structure and honest commitment. Love made conscious and grounded is the most enduring kind. Give it the architecture of your full integrity.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, TheLovers, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner knowing and a heartfelt choice now drive powerful, aligned forward movement. When you know what you value and you have chosen from that place — the path actually opens. Trust the momentum.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, TheLovers, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "From inner wisdom to loving choice, quiet inner power is the next natural expression. The deepest loves call forth the deepest reserves of courage. You are being asked for yours.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheLovers, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "Intuition and love have led to the doorway of solitude and real reflection. Go within to understand fully what your heart has been trying to tell you. The Hermit is not separating you from love — he is deepening it.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, TheLovers, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Wisdom and love aligned create a radiant, healing future. The choices you have made from your deepest truth are the stars that are guiding you home. Follow them.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, TheChariot, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Inner knowing and determined drive have earned you a fresh, open beginning. Move into it with the lightness of one who has already proven themselves. You have nothing left to prove here.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, TheChariot, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Intuition and momentum now channel into deliberate, skillful creation. You know where you are going — now use every tool at your disposal to get there with purpose and grace.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, TheChariot, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Driven by inner wisdom, momentum now yields abundant growth. Let the forward energy settle into nurturing what has arrived. The Empress asks you to stop winning for a moment and start enjoying.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, TheChariot, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Inner knowing and focused momentum now call for lasting structures. Build frameworks that will outlast the initial surge. The Emperor is asking you to turn velocity into something that endures.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, TheChariot, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Driven by intuition, forward momentum has brought you to the altar of a meaningful choice. Stop. Breathe. This decision is too important to be made at full speed. Choose with your whole being.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, TheChariot, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "Inner wisdom and determined forward motion now call for patient, compassionate endurance. The long road belongs to the steady. Speed got you here — depth will take you further.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheChariot, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "After intuitive drive and forward momentum, deep reflection is essential. Wisdom grows most profoundly in the silence after the journey. Rest. Listen. Integrate.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, TheChariot, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Inner wisdom and powerful momentum align with a radiant, hopeful future. Every step taken in alignment with your inner truth has been moving you toward the light. You are almost there.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, Strength, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Quiet inner power has earned you the freedom of a completely new beginning. Begin again with the confidence of one who has already faced the hardest things — and is still standing.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, Strength, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Intuition and inner courage now fuel deliberate, powerful conscious creation. From the inside out, you are creating a life that is truly and completely yours. The Magician confirms the power is real.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, Strength, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Inner wisdom and quiet power now bloom into abundant, nourishing richness. The strength you carry within is the most fertile force of all. What you tend with that strength cannot fail to grow.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, Strength, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "From inner knowing to patient courage, outer authority now calls. Lead with the wisdom of your inner world and the compassion of your earned strength. That is the kind of authority people actually trust.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, Strength, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Inner wisdom and quiet courage have prepared you for genuine, wholehearted love. You are ready to give and receive without reservation. The Lovers confirms what you have been quietly becoming.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, Strength, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner power and patient resilience now ignite focused, unstoppable momentum. Move with the confidence of someone who cannot be broken. That is not arrogance — that is a fact you have earned.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, Strength, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "Intuition and strength have led to the doorstep of profound wisdom. Go into solitude carrying your quiet courage. What you find there is something neither action nor strength alone could give you.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHighPriestess, Strength, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "Inner knowing and quiet strength have built a soul that can hold hope without flinching. The Star confirms what you have been preparing for. The future shines — and you are ready for its light.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, TheHermit, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "Two great inward journeys have seasoned you, and now a bold, open-hearted new beginning calls. You have done the inner work. Now step lightly into what comes next. You are ready.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, TheHermit, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "Deep inner knowing and solitary wisdom now activate deliberate, skillful creation. What was realised in silence is ready to be made real. The Magician is waiting for the wisdom the Hermit gathered.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, TheHermit, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "Two paths inward have led to an outward blossoming. The seeds planted in silence and solitude are ready to flourish in the open air. Move from the cave to the garden. The timing is right.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, TheHermit, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "Inner wisdom and the guidance of solitude now call for grounded authority. Build your structures on the bedrock of hard-earned self-knowledge. The Emperor built from wisdom is one worth following.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, TheHermit, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "Deep inner knowing and solitary reflection have led to the moment of a profound choice. You know who you are. Now choose accordingly — without apology and without hesitation.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, TheHermit, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "Inner wisdom distilled in solitude now fuels purposeful, decisive momentum. Move with the calm certainty of a soul that knows its own direction. That kind of momentum is unstoppable.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, TheHermit, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "From inner mystery to solitary wisdom, now the quiet lion must be faced. The strength required here is not loud or aggressive — it is the deep, patient kind built from everything you have learned in the silence.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheHermit, TheStar}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — HighPriestess, Hermit, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHighPriestess, TheStar, TheFool}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — HighPriestess, Star, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHighPriestess, TheStar, TheMagician}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — HighPriestess, Star, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHighPriestess, TheStar, TheEmpress}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at HighPriestess moving into Star and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHighPriestess, TheStar, TheEmperor}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — HighPriestess, Star, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHighPriestess, TheStar, TheLovers}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. HighPriestess gave you the foundation; Star is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHighPriestess, TheStar, TheChariot}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — HighPriestess, Star, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHighPriestess, TheStar, Strength}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see HighPriestess's energy in your foundation, Star's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHighPriestess, TheStar, TheHermit}] = {
        "The High Priestess marks your past, and she whispers that you already knew. There was a season when you listened to the quiet — when you trusted the pull of something you could not name. That inner knowing was your greatest compass.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see HighPriestess's energy in your foundation, Star's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, TheFool, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Empress, Fool, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, TheFool, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Empress, Fool, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, TheFool, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Empress, Fool, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, TheFool, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Empress's energy in your foundation, Fool's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, TheFool, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Empress moving into Fool and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, TheFool, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Empress, Fool, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheFool, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "These three cards together — Empress, Fool, and Hermit — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, TheFool, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Empress's energy in your foundation, Fool's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, TheMagician, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Empress's energy in your foundation, Magician's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, TheMagician, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Empress moving into Magician and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, TheMagician, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Empress's energy in your foundation, Magician's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, TheMagician, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Empress moving into Magician and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, TheMagician, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Empress's energy in your foundation, Magician's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, TheMagician, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Empress moving into Magician and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheMagician, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Magician is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, TheMagician, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Empress's energy in your foundation, Magician's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, TheHighPriestess, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Empress, HighPriestess, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, TheHighPriestess, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Empress moving into HighPriestess and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, TheHighPriestess, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Empress's energy in your foundation, HighPriestess's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, TheHighPriestess, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Empress's energy in your foundation, HighPriestess's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, TheHighPriestess, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Empress moving into HighPriestess and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, TheHighPriestess, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Empress gave you the foundation; HighPriestess is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheHighPriestess, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Empress's energy in your foundation, HighPriestess's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, TheHighPriestess, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "These three cards together — Empress, HighPriestess, and Star — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, TheEmperor, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Empress, Emperor, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, TheEmperor, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Emperor is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, TheEmperor, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Empress's energy in your foundation, Emperor's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, TheEmperor, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Emperor is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, TheEmperor, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Empress, Emperor, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, TheEmperor, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Empress moving into Emperor and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheEmperor, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Empress's energy in your foundation, Emperor's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, TheEmperor, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Empress, Emperor, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, TheLovers, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Empress, Lovers, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, TheLovers, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Lovers is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, TheLovers, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Empress moving into Lovers and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, TheLovers, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Lovers is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, TheLovers, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Empress's energy in your foundation, Lovers's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, TheLovers, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Lovers is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheLovers, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "This combination — Empress, Lovers, Hermit — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, TheLovers, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Empress, Lovers, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, TheChariot, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Empress, Chariot, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, TheChariot, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "I see Empress's energy in your foundation, Chariot's energy alive in your present moment, and Magician waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, TheChariot, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Empress, Chariot, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, TheChariot, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Empress's energy in your foundation, Chariot's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, TheChariot, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "These three cards together — Empress, Chariot, and Lovers — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, TheChariot, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Chariot is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheChariot, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Empress's energy in your foundation, Chariot's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, TheChariot, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Empress's energy in your foundation, Chariot's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, Strength, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Strength is asking something of you right now; and Fool is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, Strength, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Empress moving into Strength and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, Strength, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Strength is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, Strength, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Strength is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, Strength, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Empress moving into Strength and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, Strength, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "This combination — Empress, Strength, Chariot — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, Strength, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Empress moving into Strength and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmpress, Strength, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Strength is asking something of you right now; and Star is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, TheHermit, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Empress moving into Hermit and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, TheHermit, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Hermit is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, TheHermit, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Empress's energy in your foundation, Hermit's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, TheHermit, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Empress's energy in your foundation, Hermit's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, TheHermit, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Empress's energy in your foundation, Hermit's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, TheHermit, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Empress's energy in your foundation, Hermit's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, TheHermit, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Empress's energy in your foundation, Hermit's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheHermit, TheStar}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Hermit is asking something of you right now; and Star is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmpress, TheStar, TheFool}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Empress moving into Star and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmpress, TheStar, TheMagician}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Empress, Star, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmpress, TheStar, TheHighPriestess}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Empress, Star, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmpress, TheStar, TheEmperor}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Star is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheEmpress, TheStar, TheLovers}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Empress, Star, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmpress, TheStar, TheChariot}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Empress, Star, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmpress, TheStar, Strength}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Empress moving into Star and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmpress, TheStar, TheHermit}] = {
        "I see the Empress behind you — a time of richness, of growth so natural it almost surprised you. Things bloomed. People were drawn to you. You were in your creative prime, and whether you knew it or not, you were very much in your power.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Empress gave you the foundation; Star is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, TheFool, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Emperor, Fool, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, TheFool, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Fool is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, TheFool, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Emperor's energy in your foundation, Fool's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, TheFool, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Fool is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, TheFool, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "This combination — Emperor, Fool, Chariot — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, TheFool, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Fool is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheFool, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "This combination — Emperor, Fool, Hermit — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, TheFool, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Emperor's energy in your foundation, Fool's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, TheMagician, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Emperor's energy in your foundation, Magician's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, TheMagician, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Magician is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, TheMagician, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at Emperor moving into Magician and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, TheMagician, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Emperor moving into Magician and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, TheMagician, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Emperor's energy in your foundation, Magician's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, TheMagician, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Magician is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheMagician, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Emperor moving into Magician and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, TheMagician, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Emperor moving into Magician and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, TheHighPriestess, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Emperor moving into HighPriestess and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, TheHighPriestess, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Emperor moving into HighPriestess and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, TheHighPriestess, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Emperor's energy in your foundation, HighPriestess's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, TheHighPriestess, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Emperor moving into HighPriestess and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, TheHighPriestess, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Emperor's energy in your foundation, HighPriestess's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, TheHighPriestess, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; HighPriestess is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheHighPriestess, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; HighPriestess is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, TheHighPriestess, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Emperor moving into HighPriestess and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, TheEmpress, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Empress is asking something of you right now; and Fool is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, TheEmpress, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Emperor, Empress, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, TheEmpress, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Emperor, Empress, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, TheEmpress, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Emperor moving into Empress and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, TheEmpress, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Emperor moving into Empress and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, TheEmpress, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Empress is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheEmpress, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Emperor's energy in your foundation, Empress's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, TheEmpress, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Empress is asking something of you right now; and Star is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, TheLovers, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Emperor moving into Lovers and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, TheLovers, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Lovers is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, TheLovers, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Emperor's energy in your foundation, Lovers's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, TheLovers, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Emperor, Lovers, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, TheLovers, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Lovers is asking something of you right now; and Chariot is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, TheLovers, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "This combination — Emperor, Lovers, Strength — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheLovers, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Emperor moving into Lovers and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, TheLovers, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Lovers is asking something of you right now; and Star is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, TheChariot, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Emperor moving into Chariot and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, TheChariot, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Emperor moving into Chariot and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, TheChariot, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Chariot is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, TheChariot, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Emperor's energy in your foundation, Chariot's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, TheChariot, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Chariot is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, TheChariot, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Emperor's energy in your foundation, Chariot's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheChariot, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Emperor's energy in your foundation, Chariot's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, TheChariot, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Emperor's energy in your foundation, Chariot's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, Strength, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Emperor, Strength, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, Strength, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Emperor, Strength, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, Strength, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Strength is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, Strength, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Emperor, Strength, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, Strength, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Strength is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, Strength, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Emperor moving into Strength and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, Strength, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Emperor's energy in your foundation, Strength's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheEmperor, Strength, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Strength is asking something of you right now; and Star is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, TheHermit, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Emperor, Hermit, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, TheHermit, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Emperor, Hermit, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, TheHermit, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Emperor, Hermit, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, TheHermit, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Emperor, Hermit, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, TheHermit, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Hermit is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, TheHermit, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Hermit is asking something of you right now; and Chariot is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, TheHermit, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Emperor's energy in your foundation, Hermit's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheHermit, TheStar}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Emperor moving into Hermit and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheEmperor, TheStar, TheFool}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Emperor's energy in your foundation, Star's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheEmperor, TheStar, TheMagician}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Emperor, Star, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheEmperor, TheStar, TheHighPriestess}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Emperor moving into Star and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheEmperor, TheStar, TheEmpress}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at Emperor moving into Star and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheEmperor, TheStar, TheLovers}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Star is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheEmperor, TheStar, TheChariot}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Emperor moving into Star and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheEmperor, TheStar, Strength}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Emperor gave you the foundation; Star is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheEmperor, TheStar, TheHermit}] = {
        "The Emperor anchors your past. You have known what it is to stand firm — to be the one others looked to, to carry structure and responsibility. You built something. Perhaps it cost you, but the foundation you laid is still beneath your feet.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "This combination — Emperor, Star, Hermit — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, TheFool, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Lovers, Fool, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, TheFool, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Lovers's energy in your foundation, Fool's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, TheFool, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Lovers's energy in your foundation, Fool's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, TheFool, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; Fool is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, TheFool, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Lovers moving into Fool and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, TheFool, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Lovers, Fool, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheFool, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Lovers's energy in your foundation, Fool's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, TheFool, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "These three cards together — Lovers, Fool, and Star — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, TheMagician, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Lovers moving into Magician and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, TheMagician, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Lovers, Magician, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, TheMagician, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Lovers, Magician, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, TheMagician, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Lovers, Magician, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, TheMagician, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Lovers, Magician, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, TheMagician, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Lovers moving into Magician and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheMagician, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Lovers moving into Magician and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, TheMagician, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Lovers, Magician, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, TheHighPriestess, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Lovers moving into HighPriestess and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, TheHighPriestess, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; HighPriestess is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, TheHighPriestess, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Lovers, HighPriestess, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, TheHighPriestess, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Lovers, HighPriestess, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, TheHighPriestess, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Lovers, HighPriestess, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, TheHighPriestess, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Lovers, HighPriestess, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheHighPriestess, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; HighPriestess is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, TheHighPriestess, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Lovers moving into HighPriestess and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, TheEmpress, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Lovers's energy in your foundation, Empress's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, TheEmpress, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Lovers moving into Empress and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, TheEmpress, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Lovers, Empress, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, TheEmpress, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Lovers, Empress, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, TheEmpress, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Lovers moving into Empress and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, TheEmpress, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Lovers moving into Empress and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheEmpress, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Lovers moving into Empress and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, TheEmpress, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Lovers, Empress, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, TheEmperor, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Lovers moving into Emperor and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, TheEmperor, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "I see Lovers's energy in your foundation, Emperor's energy alive in your present moment, and Magician waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, TheEmperor, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Lovers, Emperor, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, TheEmperor, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; Emperor is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, TheEmperor, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Lovers's energy in your foundation, Emperor's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, TheEmperor, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Lovers moving into Emperor and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheEmperor, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Lovers moving into Emperor and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, TheEmperor, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Lovers, Emperor, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, TheChariot, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Lovers, Chariot, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, TheChariot, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Lovers, Chariot, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, TheChariot, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Lovers moving into Chariot and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, TheChariot, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; Chariot is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, TheChariot, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Lovers, Chariot, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, TheChariot, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; Chariot is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheChariot, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "These three cards together — Lovers, Chariot, and Hermit — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, TheChariot, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Lovers's energy in your foundation, Chariot's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, Strength, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Lovers, Strength, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, Strength, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Lovers, Strength, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, Strength, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Lovers, Strength, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, Strength, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; Strength is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, Strength, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Lovers's energy in your foundation, Strength's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, Strength, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Lovers's energy in your foundation, Strength's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, Strength, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "This combination — Lovers, Strength, Hermit — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheLovers, Strength, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "These three cards together — Lovers, Strength, and Star — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, TheHermit, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Lovers moving into Hermit and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, TheHermit, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Lovers moving into Hermit and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, TheHermit, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Lovers, Hermit, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, TheHermit, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at Lovers moving into Hermit and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, TheHermit, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Lovers moving into Hermit and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, TheHermit, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; Hermit is asking something of you right now; and Chariot is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, TheHermit, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "This combination — Lovers, Hermit, Strength — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheHermit, TheStar}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Lovers's energy in your foundation, Hermit's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheLovers, TheStar, TheFool}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Lovers, Star, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheLovers, TheStar, TheMagician}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Lovers, Star, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheLovers, TheStar, TheHighPriestess}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Lovers moving into Star and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheLovers, TheStar, TheEmpress}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at Lovers moving into Star and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheLovers, TheStar, TheEmperor}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Lovers's energy in your foundation, Star's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheLovers, TheStar, TheChariot}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "The thread running through this reading is transformation. Lovers gave you the foundation; Star is asking something of you right now; and Chariot is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheLovers, TheStar, Strength}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Lovers moving into Star and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheLovers, TheStar, TheHermit}] = {
        "The Lovers card lives in your past, and that tells me everything. There was a choice — not just of the heart, but of the soul. A fork in the road where you had to decide who you truly were. That decision still echoes.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "This combination — Lovers, Star, Hermit — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, TheFool, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "I see Chariot's energy in your foundation, Fool's energy alive in your present moment, and Magician waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, TheFool, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Fool is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, TheFool, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Chariot's energy in your foundation, Fool's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, TheFool, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Chariot moving into Fool and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, TheFool, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Chariot, Fool, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, TheFool, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Chariot moving into Fool and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheFool, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "These three cards together — Chariot, Fool, and Hermit — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, TheFool, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Chariot, Fool, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, TheMagician, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Chariot moving into Magician and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, TheMagician, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Chariot, Magician, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, TheMagician, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Chariot, Magician, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, TheMagician, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Chariot, Magician, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, TheMagician, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Chariot, Magician, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, TheMagician, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Chariot moving into Magician and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheMagician, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "This combination — Chariot, Magician, Hermit — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, TheMagician, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Chariot moving into Magician and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, TheHighPriestess, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Chariot moving into HighPriestess and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, TheHighPriestess, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Chariot moving into HighPriestess and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, TheHighPriestess, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Chariot's energy in your foundation, HighPriestess's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, TheHighPriestess, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Chariot, HighPriestess, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, TheHighPriestess, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Chariot, HighPriestess, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, TheHighPriestess, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "This combination — Chariot, HighPriestess, Strength — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheHighPriestess, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Chariot moving into HighPriestess and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, TheHighPriestess, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Chariot's energy in your foundation, HighPriestess's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, TheEmpress, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Chariot's energy in your foundation, Empress's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, TheEmpress, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Chariot, Empress, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, TheEmpress, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Chariot moving into Empress and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, TheEmpress, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Chariot, Empress, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, TheEmpress, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Chariot moving into Empress and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, TheEmpress, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Chariot, Empress, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheEmpress, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Empress is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, TheEmpress, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Chariot, Empress, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, TheEmperor, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Chariot, Emperor, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, TheEmperor, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Chariot, Emperor, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, TheEmperor, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Chariot moving into Emperor and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, TheEmperor, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Emperor is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, TheEmperor, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Chariot, Emperor, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, TheEmperor, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Chariot, Emperor, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheEmperor, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Emperor is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, TheEmperor, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Chariot, Emperor, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, TheLovers, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Chariot, Lovers, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, TheLovers, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Chariot, Lovers, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, TheLovers, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Lovers is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, TheLovers, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Lovers is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, TheLovers, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Chariot, Lovers, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, TheLovers, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "This combination — Chariot, Lovers, Strength — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheLovers, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Chariot's energy in your foundation, Lovers's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, TheLovers, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Lovers is asking something of you right now; and Star is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, Strength, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Chariot's energy in your foundation, Strength's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, Strength, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Chariot, Strength, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, Strength, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Chariot moving into Strength and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, Strength, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Chariot, Strength, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, Strength, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Chariot's energy in your foundation, Strength's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, Strength, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Chariot gave you the foundation; Strength is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, Strength, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "These three cards together — Chariot, Strength, and Hermit — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheChariot, Strength, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Chariot, Strength, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, TheHermit, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Chariot, Hermit, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, TheHermit, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Chariot, Hermit, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, TheHermit, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Chariot's energy in your foundation, Hermit's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, TheHermit, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Chariot, Hermit, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, TheHermit, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Chariot moving into Hermit and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, TheHermit, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Chariot's energy in your foundation, Hermit's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, TheHermit, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Chariot's energy in your foundation, Hermit's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheHermit, TheStar}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Chariot's energy in your foundation, Hermit's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheChariot, TheStar, TheFool}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Chariot moving into Star and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheChariot, TheStar, TheMagician}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Chariot moving into Star and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheChariot, TheStar, TheHighPriestess}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Chariot, Star, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheChariot, TheStar, TheEmpress}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Chariot, Star, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheChariot, TheStar, TheEmperor}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Chariot, Star, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheChariot, TheStar, TheLovers}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Chariot moving into Star and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheChariot, TheStar, Strength}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Chariot, Star, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheChariot, TheStar, TheHermit}] = {
        "The Chariot sits behind you, and I can see the dust still settling. You fought for something — or someone — and you were relentless. You moved through opposition the way water moves through stone. That willpower is part of who you are now.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Chariot's energy in your foundation, Star's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheFool, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "I see Strength's energy in your foundation, Fool's energy alive in your present moment, and Magician waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheFool, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Strength gave you the foundation; Fool is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheFool, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Strength, Fool, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheFool, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Strength's energy in your foundation, Fool's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheFool, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Strength's energy in your foundation, Fool's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheFool, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "This combination — Strength, Fool, Chariot — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheFool, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Strength gave you the foundation; Fool is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheFool, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Strength moving into Fool and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheMagician, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Strength, Magician, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheMagician, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Strength's energy in your foundation, Magician's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheMagician, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Strength, Magician, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheMagician, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Strength, Magician, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheMagician, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Strength's energy in your foundation, Magician's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheMagician, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Strength's energy in your foundation, Magician's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheMagician, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Strength gave you the foundation; Magician is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheMagician, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "These three cards together — Strength, Magician, and Star — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheHighPriestess, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Strength, HighPriestess, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheHighPriestess, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Strength, HighPriestess, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheHighPriestess, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Strength, HighPriestess, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheHighPriestess, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Strength, HighPriestess, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheHighPriestess, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Strength's energy in your foundation, HighPriestess's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheHighPriestess, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Strength moving into HighPriestess and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheHighPriestess, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Strength moving into HighPriestess and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheHighPriestess, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Strength moving into HighPriestess and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheEmpress, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Strength's energy in your foundation, Empress's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheEmpress, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "I see Strength's energy in your foundation, Empress's energy alive in your present moment, and Magician waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheEmpress, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Strength's energy in your foundation, Empress's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheEmpress, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Strength, Empress, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheEmpress, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Strength moving into Empress and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheEmpress, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Strength moving into Empress and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheEmpress, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "This combination — Strength, Empress, Hermit — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheEmpress, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "These three cards together — Strength, Empress, and Star — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheEmperor, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Strength, Emperor, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheEmperor, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Strength, Emperor, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheEmperor, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Strength's energy in your foundation, Emperor's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheEmperor, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Strength's energy in your foundation, Emperor's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheEmperor, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "These three cards together — Strength, Emperor, and Lovers — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheEmperor, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "This combination — Strength, Emperor, Chariot — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheEmperor, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Strength moving into Emperor and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheEmperor, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "These three cards together — Strength, Emperor, and Star — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheLovers, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "When I look at Strength moving into Lovers and arriving at Fool, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheLovers, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "I see Strength's energy in your foundation, Lovers's energy alive in your present moment, and Magician waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheLovers, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Strength moving into Lovers and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheLovers, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Strength gave you the foundation; Lovers is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheLovers, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Strength moving into Lovers and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheLovers, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Strength's energy in your foundation, Lovers's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheLovers, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Strength's energy in your foundation, Lovers's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheLovers, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Strength's energy in your foundation, Lovers's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheChariot, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Strength's energy in your foundation, Chariot's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheChariot, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Strength, Chariot, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheChariot, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Strength gave you the foundation; Chariot is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheChariot, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at Strength moving into Chariot and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheChariot, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Strength, Chariot, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheChariot, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Strength's energy in your foundation, Chariot's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheChariot, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Strength gave you the foundation; Chariot is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{Strength, TheChariot, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "These three cards together — Strength, Chariot, and Star — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheHermit, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Strength, Hermit, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheHermit, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Strength, Hermit, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheHermit, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Strength's energy in your foundation, Hermit's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheHermit, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Strength, Hermit, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheHermit, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Strength's energy in your foundation, Hermit's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheHermit, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "When I look at Strength moving into Hermit and arriving at Lovers, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheHermit, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Strength's energy in your foundation, Hermit's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheHermit, TheStar}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Strength moving into Hermit and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{Strength, TheStar, TheFool}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Strength, Star, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{Strength, TheStar, TheMagician}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Strength, Star, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{Strength, TheStar, TheHighPriestess}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Strength, Star, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{Strength, TheStar, TheEmpress}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Strength gave you the foundation; Star is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{Strength, TheStar, TheEmperor}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Strength, Star, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{Strength, TheStar, TheLovers}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "These three cards together — Strength, Star, and Lovers — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{Strength, TheStar, TheChariot}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "This combination — Strength, Star, Chariot — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{Strength, TheStar, TheHermit}] = {
        "Strength is in your past, and this is not a card that comes lightly. You have already faced the beast — whatever your personal lion was — and instead of running, you held it. That quiet courage is something you carry without fully realising it.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Strength moving into Star and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheHermit, TheFool, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Hermit, Fool, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, TheFool, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "When I look at Hermit moving into Fool and arriving at HighPriestess, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, TheFool, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at Hermit moving into Fool and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, TheFool, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Fool is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, TheFool, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "These three cards together — Hermit, Fool, and Lovers — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, TheFool, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Hermit's energy in your foundation, Fool's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, TheFool, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Hermit's energy in your foundation, Fool's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHermit, TheFool, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Hermit's energy in your foundation, Fool's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, TheMagician, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Hermit, Magician, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, TheMagician, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Hermit, Magician, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, TheMagician, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Hermit, Magician, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, TheMagician, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "These three cards together — Hermit, Magician, and Emperor — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, TheMagician, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Magician is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, TheMagician, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Hermit's energy in your foundation, Magician's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, TheMagician, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Hermit's energy in your foundation, Magician's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHermit, TheMagician, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Hermit moving into Magician and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, TheHighPriestess, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; HighPriestess is asking something of you right now; and Fool is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, TheHighPriestess, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Hermit, HighPriestess, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, TheHighPriestess, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Hermit's energy in your foundation, HighPriestess's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, TheHighPriestess, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; HighPriestess is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, TheHighPriestess, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Hermit, HighPriestess, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, TheHighPriestess, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Hermit moving into HighPriestess and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, TheHighPriestess, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Hermit, HighPriestess, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHermit, TheHighPriestess, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Hermit's energy in your foundation, HighPriestess's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, TheEmpress, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Empress is asking something of you right now; and Fool is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, TheEmpress, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Hermit moving into Empress and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, TheEmpress, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Empress is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, TheEmpress, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Hermit, Empress, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, TheEmpress, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Hermit's energy in your foundation, Empress's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, TheEmpress, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Hermit's energy in your foundation, Empress's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, TheEmpress, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Hermit, Empress, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHermit, TheEmpress, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Hermit, Empress, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, TheEmperor, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Hermit's energy in your foundation, Emperor's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, TheEmperor, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Emperor is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, TheEmperor, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Hermit, Emperor, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, TheEmperor, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Hermit, Emperor, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, TheEmperor, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Emperor is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, TheEmperor, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Hermit, Emperor, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, TheEmperor, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Hermit's energy in your foundation, Emperor's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHermit, TheEmperor, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Hermit's energy in your foundation, Emperor's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, TheLovers, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Hermit, Lovers, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, TheLovers, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Hermit moving into Lovers and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, TheLovers, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Hermit, Lovers, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, TheLovers, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Hermit, Lovers, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, TheLovers, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Hermit's energy in your foundation, Lovers's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, TheLovers, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Hermit, Lovers, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, TheLovers, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Hermit moving into Lovers and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHermit, TheLovers, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "When I look at Hermit moving into Lovers and arriving at Star, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, TheChariot, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Hermit, Chariot, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, TheChariot, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "I see Hermit's energy in your foundation, Chariot's energy alive in your present moment, and Magician waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, TheChariot, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Hermit's energy in your foundation, Chariot's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, TheChariot, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "When I look at Hermit moving into Chariot and arriving at Empress, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, TheChariot, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Hermit, Chariot, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, TheChariot, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Hermit's energy in your foundation, Chariot's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, TheChariot, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Hermit, Chariot, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheHermit, TheChariot, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "I see Hermit's energy in your foundation, Chariot's energy alive in your present moment, and Star waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, Strength, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "This combination — Hermit, Strength, Fool — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, Strength, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Hermit, Strength, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, Strength, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Strength is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, Strength, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Hermit, Strength, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, Strength, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Hermit's energy in your foundation, Strength's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, Strength, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Strength is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, Strength, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Hermit moving into Strength and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, Strength, TheStar}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Star shines in your future, and I want you to really hear this: hope is justified. Whatever road you have walked to get here, what lies ahead holds genuine healing, clarity, and renewal. You are walking toward your own light.",
        "This combination — Hermit, Strength, Star — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down three things you are genuinely hopeful about, even if that hope feels fragile. Identify one small act of renewal you can take today — something that signals to yourself that healing is allowed to happen."
    };

    map[{TheHermit, TheStar, TheFool}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Hermit, Star, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheHermit, TheStar, TheMagician}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Hermit moving into Star and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheHermit, TheStar, TheHighPriestess}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Star is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheHermit, TheStar, TheEmpress}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Star is asking something of you right now; and Empress is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheHermit, TheStar, TheEmperor}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Hermit moving into Star and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheHermit, TheStar, TheLovers}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Hermit, Star, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheHermit, TheStar, TheChariot}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Hermit's energy in your foundation, Star's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheHermit, TheStar, Strength}] = {
        "The Hermit marks your past, and that tells me you have been through a period of deep aloneness — chosen or not. You withdrew, you searched, you lit your own lantern in the dark. What you found there belongs only to you.",
        "The Star shines in your present, and after everything, she arrives like water in the desert. This is a moment of genuine renewal. Let yourself be restored. Hope is not naive right now — it is accurate. The worst has already passed.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "The thread running through this reading is transformation. Hermit gave you the foundation; Star is asking something of you right now; and Strength is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheFool, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Star gave you the foundation; Fool is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, TheFool, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Star, Fool, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, TheFool, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Star, Fool, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, TheFool, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Star moving into Fool and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, TheFool, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Star, Fool, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, TheFool, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Star moving into Fool and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, TheFool, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Star, Fool, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheFool, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "And right now, the Fool is here with you. This is a threshold moment. Something is beckoning you into unfamiliar territory, and the universe is asking whether you are willing to take the step. Fear is normal. Step anyway.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Star moving into Fool and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, TheMagician, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The thread running through this reading is transformation. Star gave you the foundation; Magician is asking something of you right now; and Fool is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, TheMagician, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Star, Magician, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, TheMagician, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "I see Star's energy in your foundation, Magician's energy alive in your present moment, and Empress waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, TheMagician, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Star gave you the foundation; Magician is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, TheMagician, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "I see Star's energy in your foundation, Magician's energy alive in your present moment, and Lovers waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, TheMagician, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Star's energy in your foundation, Magician's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, TheMagician, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "This combination — Star, Magician, Strength — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheMagician, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Magician is present with you right now, which means everything you need is already in your hands. You are not waiting for permission or resources — you have them. The question is whether you are ready to stop preparing and start creating.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "These three cards together — Star, Magician, and Hermit — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, TheHighPriestess, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Star, HighPriestess, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, TheHighPriestess, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Star moving into HighPriestess and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, TheHighPriestess, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Star, HighPriestess, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, TheHighPriestess, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Star, HighPriestess, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, TheHighPriestess, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Star gave you the foundation; HighPriestess is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, TheHighPriestess, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Star moving into HighPriestess and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, TheHighPriestess, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Star's energy in your foundation, HighPriestess's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheHighPriestess, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The High Priestess sits in your present, which tells me you are in a liminal space — between knowing and not knowing. Something is trying to surface. Do not force it. Sit in the not-yet. The answer you need will rise on its own.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "These three cards together — Star, HighPriestess, and Hermit — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, TheEmpress, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Star, Empress, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, TheEmpress, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "The thread running through this reading is transformation. Star gave you the foundation; Empress is asking something of you right now; and Magician is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, TheEmpress, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "The thread running through this reading is transformation. Star gave you the foundation; Empress is asking something of you right now; and HighPriestess is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, TheEmpress, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Star moving into Empress and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, TheEmpress, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Star, Empress, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, TheEmpress, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Star moving into Empress and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, TheEmpress, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Star's energy in your foundation, Empress's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheEmpress, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Empress is your present energy, and she is lush, warm, and generous. This is a season for receiving — for tending what is growing in your life rather than forcing new growth. Nourish yourself. What you feed will flourish.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "I see Star's energy in your foundation, Empress's energy alive in your present moment, and Hermit waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, TheEmperor, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Star's energy in your foundation, Emperor's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, TheEmperor, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Star, Emperor, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, TheEmperor, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Star, Emperor, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, TheEmperor, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Star, Emperor, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, TheEmperor, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "This combination — Star, Emperor, Lovers — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, TheEmperor, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "I see Star's energy in your foundation, Emperor's energy alive in your present moment, and Chariot waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, TheEmperor, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "When I look at Star moving into Emperor and arriving at Strength, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheEmperor, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Emperor stands squarely in your present. Order is being asked of you right now — in your work, your mind, perhaps your home. The chaos wants structure. You are being called to be the one who provides it, even if no one else will.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Star moving into Emperor and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, TheLovers, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The thread running through this reading is transformation. Star gave you the foundation; Lovers is asking something of you right now; and Fool is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, TheLovers, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "These three cards together — Star, Lovers, and Magician — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, TheLovers, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "These three cards together — Star, Lovers, and HighPriestess — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, TheLovers, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Star, Lovers, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, TheLovers, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "I see Star's energy in your foundation, Lovers's energy alive in your present moment, and Emperor waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, TheLovers, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "These three cards together — Star, Lovers, and Chariot — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, TheLovers, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "This combination — Star, Lovers, Strength — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheLovers, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Lovers are present with you, and this is not necessarily romantic — though it can be. You are standing at a crossroads that requires you to choose from your values, not your fears. What do you actually believe in? Choose that.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Star gave you the foundation; Lovers is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, TheChariot, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "These three cards together — Star, Chariot, and Fool — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, TheChariot, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Star, Chariot, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, TheChariot, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Star's energy in your foundation, Chariot's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, TheChariot, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Star, Chariot, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, TheChariot, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "The thread running through this reading is transformation. Star gave you the foundation; Chariot is asking something of you right now; and Emperor is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, TheChariot, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "These three cards together — Star, Chariot, and Lovers — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, TheChariot, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "I see Star's energy in your foundation, Chariot's energy alive in your present moment, and Strength waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    map[{TheStar, TheChariot, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Chariot is your present card, and it carries real urgency. You are in motion — or you need to be. The competing forces in your life are ready to be harnessed. Hold the reins. You have more control over this situation than you feel.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "The thread running through this reading is transformation. Star gave you the foundation; Chariot is asking something of you right now; and Hermit is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, Strength, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "I see Star's energy in your foundation, Strength's energy alive in your present moment, and Fool waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, Strength, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "When I look at Star moving into Strength and arriving at Magician, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, Strength, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "I see Star's energy in your foundation, Strength's energy alive in your present moment, and HighPriestess waiting in your future. Each of these cards has its own sacred intelligence — and here they are working together. Honour where you have been, stay present with where you are, and trust where you are going.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, Strength, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "These three cards together — Star, Strength, and Empress — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, Strength, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "When I look at Star moving into Strength and arriving at Emperor, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, Strength, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Star gave you the foundation; Strength is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, Strength, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "The thread running through this reading is transformation. Star gave you the foundation; Strength is asking something of you right now; and Chariot is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, Strength, TheHermit}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "Strength is your present card, and she comes not as a warrior but as someone who kneels down and looks the lion in the eye without flinching. Whatever you are facing right now requires patience and compassion — including toward yourself.",
        "The Hermit waits ahead of you, and this is not a warning — it is an invitation. A period of meaningful solitude and inner work is coming. Do not resist it when it arrives. The wisdom you will gather there is irreplaceable.",
        "When I look at Star moving into Strength and arriving at Hermit, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Schedule a genuine block of solitary time — a walk alone, a morning without social media, a full evening of your own company. Bring a single question into that solitude and see what surfaces when the noise fades."
    };

    map[{TheStar, TheHermit, TheFool}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Fool waits for you in the future, and that is genuinely exciting. A completely new chapter is coming — something you cannot yet imagine from where you stand. Keep your heart open and your grip loose. The best beginnings arrive unexpectedly.",
        "The thread running through this reading is transformation. Star gave you the foundation; Hermit is asking something of you right now; and Fool is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Do one thing this week that feels slightly too risky — something you have been talking yourself out of. Journal about what held you back and what happened when you stepped forward anyway."
    };

    map[{TheStar, TheHermit, TheMagician}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Magician stands in your future, which tells me that what is coming is a moment of genuine creative power. You will have the tools, the skill, and the will. When that moment arrives, do not hesitate — act with full intention.",
        "This combination — Star, Hermit, Magician — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Make a list of every resource, skill, and connection you currently have access to. Then choose one goal and apply them intentionally. Stop waiting for the perfect moment — the tools are already in your hands."
    };

    map[{TheStar, TheHermit, TheHighPriestess}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The High Priestess waits ahead of you, and she is asking you to develop your relationship with your own inner knowing. What is coming will not be solved by analysis or force. The future rewards those who have learned to trust themselves.",
        "This combination — Star, Hermit, HighPriestess — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Spend time in silence daily — even fifteen minutes. Notice what arises without analysing it. Start keeping a dream journal, or simply write down the first thought that comes each morning before you look at your phone."
    };

    map[{TheStar, TheHermit, TheEmpress}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Empress waits for you in the future, and that is a beautiful omen. Abundance is coming — growth, creativity, perhaps something that feels like home. You are moving toward a season of genuine flourishing. Let that be a comfort.",
        "This combination — Star, Hermit, Empress — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Tend to your body and your environment this week. Cook a real meal, spend time in nature, clear physical clutter, or create something with your hands. Abundance responds to attention and care — begin there."
    };

    map[{TheStar, TheHermit, TheEmperor}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Emperor waits in your future, and he arrives as both reward and responsibility. What is coming will require you to step into real authority — to lead, to organise, to be the one who holds the line. You are more ready than you know.",
        "This combination — Star, Hermit, Emperor — is asking you to trust the full arc of your story. Not just the chapter you are in, but all of it. The past holds wisdom, the present holds power, and the future holds genuine promise.",
        "Suggestion: Identify one area of your life that lacks structure and create a simple, clear system for it. This week, commit to one new boundary — and hold it without apology. Discipline is a form of self-respect."
    };

    map[{TheStar, TheHermit, TheLovers}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Lovers stand ahead of you, and this card in the future position carries weight. A meaningful choice is approaching — one that will define a significant chapter of your life. Begin now to clarify what you truly value.",
        "The thread running through this reading is transformation. Star gave you the foundation; Hermit is asking something of you right now; and Lovers is showing you what becomes possible when you answer that call. Take all three seriously.",
        "Suggestion: Write down your five deepest personal values — not what you think you should value, but what actually guides your best decisions. Use this list as a filter for the choice currently facing you."
    };

    map[{TheStar, TheHermit, TheChariot}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "The Chariot charges through your future, and that is a powerful omen for victory. What you are working toward is achievable — but it will require everything from you. Focus, commit, and refuse to be pulled off course by lesser things.",
        "When I look at Star moving into Hermit and arriving at Chariot, I see someone being shaped by their experiences in exactly the right way. You are not off-course. Every stage of this has been preparing you for the next one.",
        "Suggestion: Identify the one goal that matters most right now and remove everything from your schedule that is not contributing to it. Write down the two opposing forces in your situation and describe how you will hold both in check."
    };

    map[{TheStar, TheHermit, Strength}] = {
        "The Star rests in your past, and it is one of the most healing cards I can see here. After something broke open — and something did — you found renewal. You let yourself hope again. That mending happened quietly, but it was real.",
        "The Hermit is with you now, and he is not asking you to be social. The answers you are looking for are not outside of you. Pull back. Reduce the noise. Spend real time in your own company. Something important is waiting to be heard.",
        "Strength waits for you in the future, and she does not arrive easily. Something will test you — genuinely test the depth of your patience and your courage. But hear this: you will not break. You will be the one still standing.",
        "These three cards together — Star, Hermit, and Strength — tell me you are in a genuine transition. Something is completing and something else is being born. The wisdom here is to hold both the ending and the beginning at once, and not rush either.",
        "Suggestion: Notice where you are using force instead of patience this week. Practice approaching one difficult person or situation with gentle, steady presence instead of pressure. Observe what shifts."
    };

    return map;
}

#endif // TAROT_COMBINATIONS_H