#include "TarotDeck.h"   // in same services/ directory

void TarotDeck::initDeck() {
    cards.clear();

    // ── 1. The Fool ──────────────────────────────────────────────────────────
    Card fool("The Fool");
    fool.addMeaning("Happy",    "A joyful new journey begins. Full of optimism, embracing the unknown with spontaneity.");
    fool.addMeaning("Sad",      "Even if things feel chaotic, a fresh start is possible. Trust the process.");
    fool.addMeaning("Neutral",  "A phase of new beginnings is approaching. Remain open and curious.");
    fool.addMeaning("Confused", "The path ahead is unclear, but small steps guided by intuition help growth.");
    fool.addMeaning("Excited",  "A thrilling new chapter is opening — leap boldly and trust your instincts.");
    cards.push_back(fool);

    // ── 2. The Magician ──────────────────────────────────────────────────────
    Card magician("The Magician");
    magician.addMeaning("Happy",    "Your skills are manifesting opportunities. Confidence and creativity lead to success.");
    magician.addMeaning("Sad",      "You have the power to change your situation. Focus and action turn things around.");
    magician.addMeaning("Neutral",  "Resources and talents are aligned. Pay attention to opportunities to act.");
    magician.addMeaning("Confused", "You have all the tools you need. Take deliberate steps to bring clarity.");
    magician.addMeaning("Excited",  "Channel your electric energy into deliberate creation — the results will amaze you.");
    cards.push_back(magician);

    // ── 3. The High Priestess ────────────────────────────────────────────────
    Card highPriestess("The High Priestess");
    highPriestess.addMeaning("Happy",    "Intuition guides you to hidden truths. Reflection brings clarity and insight.");
    highPriestess.addMeaning("Sad",      "Secrets or hidden information emerge if you observe patiently.");
    highPriestess.addMeaning("Neutral",  "Intuition and inner guidance are key. Listen before acting.");
    highPriestess.addMeaning("Confused", "Not all answers are visible yet. Trust your inner voice and wait.");
    highPriestess.addMeaning("Excited",  "Your instincts are sharp right now — let enthusiasm be tempered by deep listening.");
    cards.push_back(highPriestess);

    // ── 4. The Empress ───────────────────────────────────────────────────────
    Card empress("The Empress");
    empress.addMeaning("Happy",    "Abundance and creativity surround you. Nurturing energy leads to growth.");
    empress.addMeaning("Sad",      "Focus on self-care and nurturing. Patience brings emotional and creative fulfillment.");
    empress.addMeaning("Neutral",  "Expansion and creativity are coming. Nurture your ideas and efforts.");
    empress.addMeaning("Confused", "Uncertainty exists, but patience and nurturing energy will lead to success.");
    empress.addMeaning("Excited",  "Your creative energy is overflowing — let it grow organically and abundantly.");
    cards.push_back(empress);

    // ── 5. The Emperor ───────────────────────────────────────────────────────
    Card emperor("The Emperor");
    emperor.addMeaning("Happy",    "Leadership and stability empower your decisions. Structure leads to growth.");
    emperor.addMeaning("Sad",      "Take control of your situation with discipline. Order brings calm.");
    emperor.addMeaning("Neutral",  "A period of responsibility and planning. Structure your ideas carefully.");
    emperor.addMeaning("Confused", "Focus on clarity and discipline. Authority and strategy guide your steps.");
    emperor.addMeaning("Excited",  "Harness your drive into organised action — build something that lasts.");
    cards.push_back(emperor);

    // ── 6. The Lovers ────────────────────────────────────────────────────────
    Card lovers("The Lovers");
    lovers.addMeaning("Happy",    "Important emotional choices bring harmony and connection.");
    lovers.addMeaning("Sad",      "Relationships and decisions may challenge you. Thoughtful choices matter.");
    lovers.addMeaning("Neutral",  "Alignment and harmony are possible. Consider consequences carefully.");
    lovers.addMeaning("Confused", "You may face choice dilemmas. Follow your heart and intuition.");
    lovers.addMeaning("Excited",  "A meaningful connection or decision is electrifying your path forward.");
    cards.push_back(lovers);

    // ── 7. The Chariot ───────────────────────────────────────────────────────
    Card chariot("The Chariot");
    chariot.addMeaning("Happy",    "Victory and determination guide you. Success through focus and control.");
    chariot.addMeaning("Sad",      "Discipline and willpower overcome obstacles. Steady progress matters.");
    chariot.addMeaning("Neutral",  "Movement and determination lead to progress. Direct your energy wisely.");
    chariot.addMeaning("Confused", "Control your impulses. Strategy and focus bring success.");
    chariot.addMeaning("Excited",  "You are unstoppable right now — channel every ounce of momentum toward your goal.");
    cards.push_back(chariot);

    // ── 8. Strength ──────────────────────────────────────────────────────────
    Card strength("Strength");
    strength.addMeaning("Happy",    "Inner courage and patience lead to triumph. Compassion guides action.");
    strength.addMeaning("Sad",      "Gentle perseverance brings resilience. Your strength shines quietly.");
    strength.addMeaning("Neutral",  "Calm determination and courage help manage challenges effectively.");
    strength.addMeaning("Confused", "Stay composed and patient. Inner strength resolves difficulties.");
    strength.addMeaning("Excited",  "Your passion is powerful — steady it with patience and it becomes unstoppable.");
    cards.push_back(strength);

    // ── 9. The Hermit ────────────────────────────────────────────────────────
    Card hermit("The Hermit");
    hermit.addMeaning("Happy",    "Reflection and introspection illuminate your path. Wisdom grows within.");
    hermit.addMeaning("Sad",      "Seek quiet and solitude. Understanding comes from within.");
    hermit.addMeaning("Neutral",  "A period of self-discovery is approaching. Be patient and observant.");
    hermit.addMeaning("Confused", "Step back and reflect. Solitude provides clarity and answers.");
    hermit.addMeaning("Excited",  "Before charging forward, take a breath — the answers you need are already inside you.");
    cards.push_back(hermit);

    // ── 10. The Star ─────────────────────────────────────────────────────────
    Card star("The Star");
    star.addMeaning("Happy",    "Hope and inspiration guide you. Renewed optimism and creativity flow.");
    star.addMeaning("Sad",      "Healing and guidance are available. Remain hopeful despite setbacks.");
    star.addMeaning("Neutral",  "Calm confidence and trust in the process bring positive outcomes.");
    star.addMeaning("Confused", "Look to inspiration and hope. Clarity and solutions emerge gradually.");
    star.addMeaning("Excited",  "Your optimism is perfectly aligned with the universe right now — keep shining.");
    cards.push_back(star);
}
