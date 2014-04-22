package com.ankamagames.wakfu.client.binaryStorage;

public class FightChallengeBinaryData implements dEZ {
    protected int az;
    protected int dev;
    protected String hUl;
    protected int fAx;
    protected int hUm;
    protected int hUn;
    protected int aZE;
    protected boolean fAA;
    protected int[] hUo;
    protected int[] hUp;
    protected elh[] hUq;
    
    public FightChallengeBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int arE()
    {
        return this.dev;
    }
    
    public String cpN()
    {
        return this.hUl;
    }
    
    public int bvu()
    {
        return this.fAx;
    }
    
    public int cpO()
    {
        return this.hUm;
    }
    
    public int cpP()
    {
        return this.hUn;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public boolean cpQ()
    {
        return this.fAA;
    }
    
    public int[] cpR()
    {
        return this.hUo;
    }
    
    public int[] cpS()
    {
        return this.hUp;
    }
    
    public elh[] cpT()
    {
        return this.hUq;
    }
    
    public void reset()
    {
        this.az = 0;
        this.dev = 0;
        this.hUl = null;
        this.fAx = 0;
        this.hUm = 0;
        this.hUn = 0;
        this.aZE = 0;
        this.fAA = false;
        this.hUo = null;
        this.hUp = null;
        this.hUq = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.dev = a.getInt();
        this.hUl = a.clg().intern();
        this.fAx = a.getInt();
        this.hUm = a.getInt();
        this.hUn = a.getInt();
        this.aZE = a.getInt();
        this.fAA = a.readBoolean();
        this.hUo = a.cli();
        this.hUp = a.cli();
        int i = a.getInt();
        this.hUq = new elh[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.hUq[i0] = new elh();
            this.hUq[i0].a(a);
            i0 = i0 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eFP.getId();
    }
}