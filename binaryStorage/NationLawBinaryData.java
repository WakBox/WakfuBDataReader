package com.ankamagames.wakfu.client.binaryStorage;

public class NationLawBinaryData implements dEZ {
    protected int az;
    protected int cep;
    protected String[] aZq;
    protected int ceq;
    protected int cer;
    protected int ces;
    protected boolean cet;
    protected boolean ceu;
    protected boolean cev;
    protected boolean cew;
    protected int[] cex;
    
    public NationLawBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int Wp()
    {
        return this.cep;
    }
    
    public String[] getParams()
    {
        return this.aZq;
    }
    
    public int Wq()
    {
        return this.ceq;
    }
    
    public int Wr()
    {
        return this.cer;
    }
    
    public int Ws()
    {
        return this.ces;
    }
    
    public boolean Wt()
    {
        return this.cet;
    }
    
    public boolean Wu()
    {
        return this.ceu;
    }
    
    public boolean Wv()
    {
        return this.cev;
    }
    
    public boolean Ww()
    {
        return this.cew;
    }
    
    public int[] Wx()
    {
        return this.cex;
    }
    
    public void reset()
    {
        this.az = 0;
        this.cep = 0;
        this.aZq = null;
        this.ceq = 0;
        this.cer = 0;
        this.ces = 0;
        this.cet = false;
        this.ceu = false;
        this.cev = false;
        this.cew = false;
        this.cex = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.cep = a.getInt();
        this.aZq = a.cll();
        this.ceq = a.getInt();
        this.cer = a.getInt();
        this.ces = a.getInt();
        this.cet = a.readBoolean();
        this.ceu = a.readBoolean();
        this.cev = a.readBoolean();
        this.cew = a.readBoolean();
        this.cex = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eEp.getId();
    }
}